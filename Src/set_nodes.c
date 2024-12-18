/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:30:33 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 09:49:52 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_points(t_map *map, t_point **points, int zoom, int alt)
{
	int	i;
	int	j;
	int	tmp;
	t_point	*l;

	i = 0;
	j = 0;
	tmp = 0;
	l = *points;
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			tmp = l->xp;
			l->xp = (map->size_x / 2) * zoom + zoom * ((tmp - l->yp) * 0.866);
			l->yp = (map->size_y / 2) * zoom + zoom * ((tmp + l->yp) * 0.5) - alt * l->z;
			l = get_current(l);
			i++;
		}
		j++;
	}
}
