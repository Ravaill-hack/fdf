/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:43:38 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/11 13:51:51 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ext_col_low(char *str, int ind)
{
	char	*raw;
	int		nb;

	raw = ft_substr(str, (unsigned)ind, 6);
	nb = ft_atoi_base(raw, "0123456789abcdef");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col_up(char *str, int ind)
{
	char	*raw;
	int		nb;

	raw = ft_substr(str, (unsigned)ind, 6);
	nb = ft_atoi_base(raw, "0123456789ABCDEF");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col(char *str, t_map *map)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == ',')
			start = i + 3;
	}
	if (start == 0)
		return (0xFFFFFF);
	map->is_col = 1;
	i = 0;
	while (i <= 5 && str[start + i] != '\0')
	{
		if (ft_strchr("0123456789abcdef", str[start + i]) != NULL)
			return (ext_col_low(str, start + i));
		else if (ft_strchr("0123456789ABCDEF", str[start + i]) != NULL)
			return (ext_col_up(str, start + i));
		i++;
	}
	return (0xFFFFFF);
}

void	ft_find_col(t_map *map, t_point *p)
{
	int		delt_z;
	int		z0;
	float	rz;

	delt_z = map->z_max - map->z_min;
	z0 = p->z - map->z_min;
	if (p->z == map->z_min)
		p->col = 255;
	else if (p->z == map->z_max)
		p->col = 16711680;
	if (map->z_min == map->z_max || p->z == map->z_min || p->z == map->z_max)
		return ;
	rz = (p->z / delt_z);
	if (rz < (float)0.25)
		p->col = ft_deg_bc(rz);
	else if ((float)0.25 <= rz && rz < (float)0.5)
		p->col = ft_deg_cv(rz);
	else if ((float)0.5 <= rz && rz < (float)0.75)
		p->col = ft_deg_vj(rz);
	else
		p->col = ft_deg_jr(rz);
}

int	ft_deg_bc(float rz)
{
	int	res;

	(void) rz;
	res = 0;
	return (res);
}

int	ft_deg_cv(float rz)
{
	int	res;

	(void) rz;
	res = 0;
	if (rz == 0.25)
		return (65535);
	return (res);
}

int	ft_deg_vj(float rz)
{
	int	res;

	(void) rz;
	res = 0;
	if (rz == 0.5)
		return (65280);
	return (res);
}

int	ft_deg_jr(float rz)
{
	int	res;

	(void) rz;
	res = 0;
	if (rz == 0.75)
		return (16776960);
	return (res);
}
