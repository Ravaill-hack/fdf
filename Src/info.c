/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:16 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 12:23:05 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	print_info_list(t_point *nodes)
{
	while (nodes)
	{
		ft_printf("\nx : %d, y : %d, z : %d\n", nodes->x, nodes->y, nodes->z);
		ft_printf("adr : %p\n", nodes);
		ft_printf("up : %p, down : %p, left : %p, right : %p\n", nodes->up, nodes->dow, nodes->lft, nodes->rgt);
		nodes = nodes->next;
	}
}

void	print_info_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\n\ntitle : %s\n", map->title);
	ft_printf("path : %s\n", map->path);
	ft_printf("x size : %d\n", map->size_x);
	ft_printf("y size : %d\n\n", map->size_y);
	while (j < map->size_y)
	{
		i = 0;
		while (i < map->size_x)
		{
			ft_printf("%d ", map->map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}