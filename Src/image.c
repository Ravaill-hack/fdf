/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/08 15:24:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	init_image(t_var *var)
{
	double	zoomx;
	double	zoomy;
	double	zoom;
	double	deltx;

	deltx = (double)var->map->size_x * 0.5 + (double)var->map->size_y * 0.866;
	zoomx = ((double)X_WIN) / deltx;
	zoomy = ((double)Y_WIN) / ((double)var->map->size_x);
	if (zoomx > zoomy)
		zoom = zoomy;
	else
		zoom = zoomx;
	var->att.zoom = zoom;
	var->att.fac_z = 1;
	var->att.x0 = X_WIN / 2;
	var->att.y0 = 0;
	var->att.ang_x = 45;
	var->att.ang_y = 0;
	var->att.ang_z = 45;
	draw_image(var);
}

void	ft_clear_image(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < Y_WIN)
	{
		x = 0;
		while (x < X_WIN)
		{
			draw_point(var, x, y, 0);
			x++;
		}
		y++;
	}
}

void	ft_set_image(t_var *var)
{
	draw_image(var);
	mlx_put_image_to_window(var->mlx_p, var->win_p, var->img->im_p, 0, 0);
}

void	draw_image(t_var *var)
{
	t_point	*a;

	a = *(var->map->point);
	ft_set_alt(var, var->att.fac_z);
	ft_set_zoom(var, var->att.zoom);
	ft_set_rot(var, var->att.ang_x, var->att.ang_y, var->att.ang_z);
	ft_set_offset(var, var->att.x0, var->att.y0);
	while (a)
	{
		if (a->up != NULL)
			draw_line(var, a, a->up);
		if (a->lft != NULL)
			draw_line(var, a, a->lft);
		a = a->next;
	}
}

void	draw_point(t_var *var, int x, int y, int col)
{
	char	*ptr;

	if (x < 0 || x >= X_WIN || y < 0 || y >= Y_WIN)
		return ;
	ptr = var->img->im + (y * var->img->sl) + x * (var->img->bp / 8);
	*(int *)ptr = col;
}
