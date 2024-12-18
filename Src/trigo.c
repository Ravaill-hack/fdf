/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:31 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 15:18:35 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	set_default_zoom(t_map *map)
{
	double	lft[2];
	double	lft_tmp[2];
	double	rgt[2];
	double	rgt_tmp[2];
	double	dow[2];
	double	dow_tmp[2];

	dow_tmp[0] = (double)(map->size_x) - 1.0;
	dow_tmp[1] = (double)(map->size_y) - 1.0;
	dow[0] = (dow_tmp[0] - dow_tmp[1]) * 0.866;
	dow[1] = (dow_tmp[0] + dow_tmp[1]) * 0.5;
	lft_tmp[1] = (double)(map->size_y) - 1.0;
	lft[0] = (- lft_tmp[1]) * 0.866;
	lft[1] = (lft_tmp[1]) * 0.5;
	rgt_tmp[0] = (double)(map->size_x) - 1.0;
	rgt[0] = (rgt_tmp[0]) * 0.866;
	rgt[1] = (rgt_tmp[0]) * 0.5;
	if (dow[1] >= (rgt[0] - lft[0]))
		return((int)(((double)(map->win_y))/(dow[1])));
	else
		return((int)(((double)(map->win_x))/(rgt[0] - lft[0])));
}

int	set_y_offset(t_map *map)
{
	double	dow[2];
	double	dow_tmp[2];

	dow_tmp[0] = (double)(map->size_x) - 1.0;
	dow_tmp[1] = (double)(map->size_y) - 1.0;
	dow[1] = (dow_tmp[0] + dow_tmp[1]) * 0.5;
	return((int)(((map->win_y) / 2) - (dow[1] / 2)));
}
