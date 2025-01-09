/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:25:53 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/09 12:24:04 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	draw_line(t_var *var, t_point *p1, t_point *p2)
{
	int		dxy[2];
	float	slope;

	if (p1->x == p2->x)
	{
		draw_vertical_line(var, p1, p2);
		return (0);
	}
	if (p1->y == p2->y)
	{
		draw_horizontal_line(var, p1, p2);
		return (0);
	}
	dxy[0] = p2->x - p1->x;
	dxy[1] = p2->y - p1->y;
	slope = ((float)(dxy[1])) / ((float)(dxy[0]));
	if (slope < 1.0 && slope > -1.0)
		draw_oth_line(var, p1, p2, dxy);
	else
		draw_oth_line_rev(var, p1, p2, dxy);
	return (0);
}

void	draw_vertical_line(t_var *var, t_point *p1, t_point *p2)
{
	int	y0;
	int	d;

	y0 = p1->y;
	while (y0 != p2->y)
	{
		d = abs(y0 - (p1->y));
		draw_point(var, p1->x, y0, ft_col(p1->col, p2->col, p2->y - p1->y, d));
		if (p1->y > p2->y)
			y0--;
		else
			y0++;
	}
	d = abs(y0 - (p1->y));
	draw_point(var, p1->x, p1->y, ft_col(p1->col, p2->col, p2->y - p1->y, d));
}

void	draw_horizontal_line(t_var *var, t_point *p1, t_point *p2)
{
	int	x0;
	int	d;

	x0 = p1->x;
	while (x0 != p2->x)
	{
		d = abs(x0 - (p1->x));
		draw_point(var, x0, p1->y, ft_col(p1->col, p2->col, p2->x - p1->x, d));
		if (p1->x > p2->x)
			x0--;
		else
			x0++;
	}
	d = abs(x0 - (p1->x));
	draw_point(var, p1->x, p1->y, ft_col(p1->col, p2->col, p2->x - p1->x, d));
}

void	draw_oth_line(t_var *var, t_point *p1, t_point *p2, int dxy[2])
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dxy[1]) - abs(dxy[0]);
	l.x0 = p1->x;
	l.y0 = p1->y;
	while (++l.i <= abs(dxy[0]))
	{
		draw_point(var, l.x0, l.y0, ft_col(p1->col, p2->col, dxy[0], l.i));
		if (dxy[0] > 0)
			l.x0 += 1;
		else
			l.x0 -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dxy[1]);
		else
		{
			if (dxy[1] > 0)
				l.y0 += 1;
			else
				l.y0 -= 1;
			l.p = l.p + 2 * abs(dxy[1]) - 2 * abs(dxy[0]);
		}
	}
}

void	draw_oth_line_rev(t_var *var, t_point *p1, t_point *p2, int dxy[2])
{
	t_line	l;

	l.i = -1;
	l.p = 2 * abs(dxy[1]) - abs(dxy[0]);
	l.x0 = p1->x;
	l.y0 = p1->y;
	while (++l.i < abs(dxy[1]))
	{
		draw_point(var, l.x0, l.y0, ft_col(p1->col, p2->col, dxy[1], l.i));
		if (dxy[1] > 0)
			l.y0 += 1;
		else
			l.y0 -= 1;
		if (l.p < 0)
			l.p = l.p + 2 * abs(dxy[0]);
		else
		{
			if (dxy[0] > 0)
				l.x0 += 1;
			else
				l.x0 -= 1;
			l.p = l.p + 2 * abs(dxy[0]) - 2 * abs(dxy[1]);
		}
	}
}
