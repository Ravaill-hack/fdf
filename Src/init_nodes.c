/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:17:00 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 11:33:37 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	fill_points(t_map *map, t_point **points)
{
	int	i;
	int	j;
	t_point	*current;

	i = 0;
	j = 0;
	current = *points;
	while (j < (map->size_y))
	{
		i = 0;
		while (i < (map->size_x))
		{
			current->x = i;
			current->y = j;
			current->z = map->map[j][i];
			current->xp = current->x;
			current->yp = current->y;
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
	points = (t_point **)malloc(sizeof(t_point *));
	if (!points)
		return (NULL);
	(*points) = NULL;
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
