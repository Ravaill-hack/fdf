/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:26:13 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 12:26:53 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

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
