/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 16:15:34 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_points(t_map *map, t_point **points)
{
	int	i;
	int	tmp;
	int	zoom;
	t_point	*l;

	i = 0;
	tmp = 0;
	l = *points;
	zoom = set_default_zoom(map);
	while (i < ((map->size_y) * (map->size_x)))
	{
		tmp = l->xp;
		l->xp = set_x_offset(map, zoom) + zoom * ((tmp - l->yp) * 0.866);
		l->yp = set_y_offset(map, zoom) + zoom * ((tmp + l->yp) * 0.5) - 1.2195 * zoom * l->z;
		l = get_current(l);
		i++;
	}
}

void	set_zoom(t_point **points, double zoom)
{
	t_point	*l;

	l = *points;
	while (l)
	{
		l->xp = (int)(zoom * l->xp);
		l->yp = (int)(zoom * l->yp);
		l = get_current(l);
	}
}
