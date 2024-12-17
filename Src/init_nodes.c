/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:17:00 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 16:24:11 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	fill_points(t_map *map, t_point **points)
{
	int	i;
	int	j;
	int	zoom;
	t_point	*current;

	i = 0;
	j = 0;
	zoom = 100;
	current = *points;
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			current->x = i;
			current->y = j;
			current->z = map->map[j][i];
			current->xp = current->x * zoom + 60 * current->y + 200;
			current->yp = current->y * zoom - 40 * current->x + 400 - 20 * current->z;
			current = get_current(current);
			i++;
		}
		j++;
	}
}

t_point	**create_list(t_map *map, void *mlx_p, void *win_p)
{
	t_point	**points;
	int	i;
	int	j;

	i = 0;
	j = 0;
	points = (t_point **)malloc(sizeof(t_point *) * (map->size_y) * (map->size_x));
	if (!points)
		return (NULL);
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			fdf_lstadd_right(points, init_param(mlx_p, win_p));
			i++;
		}
		j++;
	}
	fill_points(map, points);
	find_neighbours(map, points);
	return (points);
}
