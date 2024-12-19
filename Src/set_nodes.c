/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 11:40:18 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_points(t_map *map, t_point **points)
{
	int		i;
	int		t;
	int		zo;
	t_point	*l;

	i = 0;
	t = 0;
	l = *points;
	zo = set_default_zoom(map);
	while (i < ((map->size_y) * (map->size_x)))
	{
		t = l->xp;
		l->xp = x_off(map, zo) + zo * ((t - l->yp) * 0.866);
		l->yp = y_off(map, zo) + zo * ((t + l->yp) * 0.5) - 0.2 * zo * l->z;
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
