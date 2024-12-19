/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:02:30 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 11:42:08 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	move_up(t_point **nodes)
{
	t_point	*l;

	l = *nodes;
	while (l)
	{
		l->yp = l->yp - 100;
		l = get_current(l);
	}
	mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
	lines(*nodes);
}

void	move_dow(t_point **nodes)
{
	t_point	*l;

	l = *nodes;
	while (l)
	{
		l->yp = l->yp + 100;
		l = get_current(l);
	}
	mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
	lines(*nodes);
}

void	move_lft(t_point **nodes)
{
	t_point	*l;

	l = *nodes;
	while (l)
	{
		l->xp = l->xp - 100;
		l = get_current(l);
	}
	mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
	lines(*nodes);
}

void	move_rgt(t_point **nodes)
{
	t_point	*l;

	l = *nodes;
	while (l)
	{
		l->xp = l->xp + 100;
		l = get_current(l);
	}
	mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
	lines(*nodes);
}

void	move(int keycode, t_point **nodes)
{
	if (keycode == 65362)
		move_up(nodes);
	if (keycode == 65364)
		move_dow(nodes);
	if (keycode == 65361)
		move_lft(nodes);
	if (keycode == 65363)
		move_rgt(nodes);
}
