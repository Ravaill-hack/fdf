/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:53:33 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/09 10:55:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ft_rotate_z(t_var *var, int az)
{
	t_point	*node;
	float	rz;
	int		temp;

	rz = az * PI / 180;
	node = *(var->map->point);
	while (node != NULL)
	{
		temp = node->x;
		node->x = (int)(temp * cos(rz) - node->y * sin(rz));
		node->y = (int)(temp * sin(rz) + node->y * cos(rz));
		node = get_next(node);
	}
	return (0);
}

int	ft_rotate_y(t_var *var, int ay)
{
	t_point	*node;
	float	ry;
	int		temp;

	ry = ay * PI / 180;
	node = *(var->map->point);
	while (node != NULL)
	{
		temp = node->x;
		node->x = (int)(temp * cos(ry) + node->z * sin(ry));
		node->z = (int)(temp * sin(ry) + node->z * cos(ry));
		node = get_next(node);
	}
	return (0);
}

int	ft_rotate_x(t_var *var, int ax)
{
	t_point	*node;
	float	rx;
	int		temp;

	rx = ax * PI / 180;
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
