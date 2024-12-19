/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:59:44 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 17:29:52 by lmatkows         ###   ########.fr       */
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

	dow[0] = (map->size_x - map->size_y) * 0.866;
	dow[1] = (map->size_x + map->size_y - 2.0) * 0.5;
	lft_tmp[1] = (double)(map->size_y) - 1.0;
	lft[0] = (-lft_tmp[1]) * 0.866;
	lft[1] = (lft_tmp[1]) * 0.5;
	rgt_tmp[0] = (double)(map->size_x) - 1.0;
	rgt[0] = (rgt_tmp[0]) * 0.866;
	rgt[1] = (rgt_tmp[0]) * 0.5;
	if (dow[1] >= (rgt[0] - lft[0]))
		return ((int)(((double)(map->win_y)) / (dow[1])));
	else
		return ((int)(((double)(map->win_x)) / (rgt[0] - lft[0])));
}

void	zoom(int keycode, t_point **nodes)
{
	if (keycode == XK_KP_Add)
	{
		set_zoom(nodes, 1.1);
		mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
		lines(*nodes);
	}
	if (keycode == XK_KP_Subtract)
	{
		set_zoom(nodes, 0.9);
		mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
		lines(*nodes);
	}
}
