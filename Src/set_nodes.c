/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 12:01:06 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_points(t_map *map, t_point **points, int alt)
{
	int	i;
	int	j;
	int	tmp;
	int	zoom;
	int	off_x;
	int off_y;
	t_point	*l;

	i = 0;
	j = 0;
	tmp = 0;
	l = *points;
	//zoom = set_default_zoom(map);
	zoom = 200;
	off_x = (map->win_x / 2);
	off_y = (map->win_y / 2) - (map->size_y / 2) * zoom;
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			tmp = l->xp;
			l->xp = off_x + zoom * ((tmp - l->yp) * 0.866);
			l->yp = off_y + zoom * ((tmp + l->yp) * 0.5) - alt * l->z;
			l = get_current(l);
			i++;
		}
		j++;
	}
}
