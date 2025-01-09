/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/09 11:07:28 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*ft_lst_last(t_point *nodes)
{
	while (nodes && nodes->next)
		nodes = nodes->next;
	return (nodes);
}

void	ft_set_alt(t_var *var, float fact)
{
	t_point	*node;

	node = *(var->map->point);
	while (node != NULL)
	{
		node->z = (int)(fact * node->z0);
		node = get_next(node);
	}
}

void	ft_set_zoom(t_var *var, float zoom)
{
	t_point	*node;

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
	t_point	*node;

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
	ft_rotate_z (var, az);
	ft_rotate_y (var, ay);
	ft_rotate_x (var, ax);
	return (0);
}
