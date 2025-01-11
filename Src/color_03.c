/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:06:05 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/11 14:59:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

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
	int	green;

	if (rz == 0.00)
		return (255);
	rz = rz / (float)0.25;
	green = (int)(255 * rz);
	res = 255 + green * 256;
	return (res);
}

int	ft_deg_cv(float rz)
{
	int	res;
	int	blue;

	if (rz == 0.25)
		return (65535);
	rz = (rz - (float)0.25) / (float)0.25;
	blue = (int)(255 * rz);
	res = 65535 - blue;
	return (res);
}

int	ft_deg_vj(float rz)
{
	int	res;
	int red;

	if (rz == 0.5)
		return (65280);
	rz = (rz - (float)0.5) / (float)0.25;
	red = (int)(255 * rz);
	res = 65280 + red * 65536;
	return (res);
}

int	ft_deg_jr(float rz)
{
	int	res;
	int green;

	if (rz == 0.75)
		return (16776960);
	if (rz == 1.00)
		return (16711680);
	rz = (rz - (float)0.75) / (float)0.25;
	green = 255 - (int)(255 * rz);
	res = 16776960 - green * 256;
	return (res);
}
