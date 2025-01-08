/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/08 15:27:02 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	ft_set_alt(t_var *var, double fact)
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->z = (int)(fact * node->z0);
		node = get_next(node);
	}
}

void	ft_set_zoom(t_var *var, double zoom)
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->x = (int)(node->x0 * zoom);
		node->y = (int)(node->y0 * zoom);
		node = get_next(node);
	}
}

void	ft_set_offset(t_var *var, int x_off, int y_off)
{
	t_point *node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->x = (node->x + x_off);
		node->y = (node->y + y_off);
		node = get_next(node);
	}
}

int	ft_set_rot(t_var *var, int ax, int ay, int az)
{
	t_point *node;
	double	rx;
	double	ry;
	double	rz;
	int		temp;

	rx = ax * PI / 180;
	ry = ay * PI / 180;
	rz = az * PI / 180;	
	//rotation de rz autour de z
	node = *(var->map->point);
	while (node != NULL)
	{
		temp = node->x;
		node->x = (int)(temp * cos(rz) - node->y * sin(rz));
		node->y = (int)(temp * sin(rz) + node->y * cos(rz));
		node = get_next(node);
	}
	//rotation de ry autour de y
	node = *(var->map->point);
	while (node != NULL)
	{
		temp = node->x;
		node->x = (int)(temp * cos(ry) + node->z * sin(ry));
		node->z = (int)(temp * sin(ry) + node->z * cos(ry));
		node = get_next(node);
	}
	//rotation de rz autour de x
	node = *(var->map->point);
	while (node != NULL)
	{
		temp = node->y;
		node->y = (int)(temp * cos(rx) - node->z * sin(rx));
		node->z = (int)(temp * sin(rx) + node->z * cos(rx));
		node = get_next(node);
	}
	return (0);
}
