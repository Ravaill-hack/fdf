/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 15:23:06 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_points(t_map *map, t_point **points, int alt)
{
	int	i;
	int	j;
	int	tmp;
	int	zoom;
	t_point	*l;

	i = 0;
	j = 0;
	tmp = 0;
	l = *points;
	zoom = set_default_zoom(map);
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			tmp = l->xp;
			l->xp = zoom * ((tmp - l->yp) * 0.866);
			l->yp = /*map->win_y / 2 + */ zoom * ((tmp + l->yp) * 0.5) - alt * l->z;
			l = get_current(l);
			i++;
		}
		j++;
	}
}
