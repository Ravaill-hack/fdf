/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:53:20 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 16:01:05 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	draw_line(t_point *p1, t_point *p2)
{
	int	dx;
	int	dy;
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
		draw_other_line(p1, p2, dx, dy);
	else
		draw_other_line_rev(p1, p2, dx, dy);
	return (0);
}

int	draw_vertical_line(t_point *p1, t_point *p2)
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
	return (0);
}

int	draw_horizontal_line(t_point *p1, t_point *p2)
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
	return (0);
}

int	draw_other_line(t_point *p1, t_point *p2, int dx, int dy)
{
	int	i;
	int	p;
	int	x;
	int	y;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	x = p1->xp;
	y = p1->yp;
	(void) p2;
	mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
	while (i < abs(dx))
	{
		i += 1;
		if(dx > 0)
			x += 1;
		else
			x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				y += 1;
			else
				y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
	}
	return (0);
}

int	draw_other_line_rev(t_point *p1, t_point *p2, int dx, int dy)
{
	int	i;
	int	p;
	int	x;
	int	y;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	x = p1->xp;
	y = p1->yp;
	(void) p2;
	mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
	while (i < abs(dy))
	{
		i += 1;
		if(dy > 0)
			y += 1;
		else
			y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				x += 1;
			else
				x -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		mlx_pixel_put(p1->p_mlx, p1->p_win, x, y, p1->col);
	}
	return (0);
}
