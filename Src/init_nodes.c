/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:17:00 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/16 21:26:06 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*fdf_lstlast(t_point *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	fdf_lstadd_right(t_point **points, t_point *new)
{
	if (!(*points))
		*points = new;
	else
		fdf_lstlast(*points)->next = new;
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
	return (points);
}

t_point	*get_current(t_point *lst)
{
	lst = lst->next;
	if(lst)
		return (lst);
	else
		return (NULL);
}

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
			current->y = map->size_y - 1 - j;
			current->z = map->map[j][i];
			current = get_current(current);
			i++;
		}
		j++;
	}
}

t_point	*find_up(t_map *map, t_point *point, t_point *first)
{
	if (point->y == map->size_y - 1)
		return (NULL);
	while (first)
	{
		if((first->y == point->y + 1) && (first->x == point->x))
			return (first);
		first = first->next;
	}
	return (NULL);
}

t_point	*find_dow(t_point *point, t_point *first)
{
	if (point->y == 0)
		return (NULL);
	while (first)
	{
		if((first->y == point->y - 1) && (first->x == point->x))
			return (first);
		first = first->next;
	}
	return (NULL);	
}

t_point	*find_lft(t_point *point, t_point *first)
{
	if (point->x == 0)
		return (NULL);
	while (first)
	{
		if((first->y == point->y) && (first->x == point->x - 1))
			return (first);
		first = first->next;
	}
	return (NULL);
}

t_point	*find_rgt(t_map *map, t_point *point, t_point *first)
{
	if (point->x == map->size_x - 1)
		return (NULL);
	while (first)
	{
		if((first->y == point->y) && (first->x == point->x + 1))
			return (first);
		first = first->next;
	}
	return (NULL);
}

void	find_neighbours(t_map *map, t_point **points)
{
	t_point	*current;

	current = *points;
	while (current)
	{
		current->lft = find_lft(current, *points);
		current->rgt = find_rgt(map, current, *points);
		current->dow = find_dow(current, *points);
		current->up = find_up(map, current, *points);
		current = current->next;
	}
}
