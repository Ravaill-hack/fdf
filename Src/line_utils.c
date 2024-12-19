/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:53:20 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 12:31:04 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	draw_line(t_point *p1, t_point *p2)
{
	int		dx;
	int		dy;
	double	slope;

	if (p1->xp == p2->xp)
	{
		draw_vertical_line(p1, p2);
		return (0);
	}
	if (p1->yp == p2->yp)
	{
		draw_horizontal_line(p1, p2);
		return (0);
	}
	dx = p2->xp - p1->xp;
	dy = p2->yp - p1->yp;
	slope = ((double)dy) / ((double)dx);
	if (slope < 1.0 && slope > -1.0)
		draw_other_line(p1, dx, dy);
	else
		draw_other_line_rev(p1, dx, dy);
	return (0);
}

void	draw_vertical_line(t_point *p1, t_point *p2)
{
	int	x;
	int	y;

	x = p1->xp;
	y = p1->yp;
	while (y != p2->yp)
	{
		mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
		if (p1->yp > p2->yp)
			y--;
		else
			y++;
	}
	mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
}

void	draw_horizontal_line(t_point *p1, t_point *p2)
{
	int	x;
	int	y;

	x = p1->xp;
	y = p1->yp;
	while (x != p2->xp)
	{
		mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
		if (p1->xp > p2->xp)
			x--;
		else
			x++;
	}
	mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
}

void	draw_other_line(t_point *p1, int dx, int dy)
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dy) - abs(dx);
	l.x = p1->xp;
	l.y = p1->yp;
	while (++l.i <= abs(dx))
	{
		mlx_pixel_put(p1->p_mlx, p1->p_win, l.x, l.y, p1->col);
		if (dx > 0)
			l.x += 1;
		else
			l.x -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				l.y += 1;
			else
				l.y -= 1;
			l.p = l.p + 2 * abs(dy) - 2 * abs(dx);
		}
	}
}

void	draw_other_line_rev(t_point *p1, int dx, int dy)
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dy) - abs(dx);
	l.x = p1->xp;
	l.y = p1->yp;
	while (++l.i < abs(dy))
	{
		mlx_pixel_put(p1->p_mlx, p1->p_win, l.x, l.y, p1->col);
		if (dy > 0)
			l.y += 1;
		else
			l.y -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				l.x += 1;
			else
				l.x -= 1;
			l.p = l.p + 2 * abs(dx) - 2 * abs(dy);
		}
	}
}
