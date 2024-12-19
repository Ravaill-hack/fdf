/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:43:38 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 14:19:44 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ext_col_low(char *str, int ind)
{
	char	*raw;
	char	col[6];
	int		nb;
	int		i;
	int		j;

	i = 0;
	raw = ft_substr(str, (unsigned)ind, 6);
	j = ft_strlen(raw) - 1;
	while (i < 6)
	{
		col[i] = '0';
		i++;
	}
	i = 5;
	while (j >= 0)
	{
		col[i] = raw[j];
		i--;
		j--;
	}
	nb = ft_atoi_base(col, "0123456789abcdef");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col_up(char *str, int ind)
{
	char	*raw;
	char	col[6];
	int		nb;
	int		i;
	int		j;

	i = 0;
	raw = ft_substr(str, (unsigned)ind, 6);
	j = ft_strlen(raw) - 1;
	while (i < 6)
	{
		col[i] = '0';
		i++;
	}
	i = 5;
	while (j >= 0)
	{
		col[i] = raw[j];
		i--;
		j--;
	}
	nb = ft_atoi_base(col, "0123456789ABCDEF");
	free (raw);
	raw = NULL;
	return (nb);
}

int	ext_col(char *str)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			start = i + 3;
		i++;
	}
	if (start == 0)
		return (0xFFFFFF);
	else
	{
		while (str[start] != '\0')
		{
			if (ft_strchr("abcdef", str[start]) != NULL)
				return (ext_col_low(str, start));
			start++;
		}
	}
	return (ext_col_up(str, start));
}
