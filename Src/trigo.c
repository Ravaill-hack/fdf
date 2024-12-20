/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:31 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 10:31:02 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

double	find_z_max(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = map->map[j][i];
	while (j < map->size_y)
	{
		i = 0;
		while (i < map->size_x)
		{
			if (map->map[j][i] > max)
				max = map->map[j][i];
			i++;
		}
		j++;
	}
	return (max);
}

double	find_z_min(t_map *map)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = map->map[j][i];
	while (j < map->size_y)
	{
		i = 0;
		while (i < map->size_x)
		{
			if (map->map[j][i] < min)
				min = map->map[j][i];
			i++;
		}
		j++;
	}
	return (min);
}

double	set_default_zz(t_map *map)
{
	double	delta_z;

	delta_z = fabs(find_z_max(map)) + fabs(find_z_min(map));
	return (100.0 / delta_z);
}

int	x_off(t_map *map, int zo)
{
	double	l[2];
	double	l_tmp[2];
	double	r[2];
	double	r_tmp[2];

	l_tmp[1] = (double)(map->size_y) - 1.0;
	l[0] = (-l_tmp[1]) * 0.866;
	l[1] = (l_tmp[1]) * 0.5;
	r_tmp[0] = (double)(map->size_x) - 1.0;
	r[0] = (r_tmp[0]) * 0.866;
	r[1] = (r_tmp[0]) * 0.5;
	return ((int)((map->win_x - zo * (r[0] - l[0] - 2 * fabs(l[0]))) / 2));
}

int	y_off(t_map *map, int zo)
{
	double	dow[2];
	double	dow_tmp[2];

	dow_tmp[0] = (double)(map->size_x) - 1.0;
	dow_tmp[1] = (double)(map->size_y) - 1.0;
	dow[1] = (dow_tmp[0] + dow_tmp[1]) * 0.5;
	return ((int)((map->win_y - zo * dow[1]) / 2));
}
