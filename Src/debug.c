/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:16 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/01/10 14:09:00 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	print_info_list(t_point *n)
{
	while (n)
	{
		ft_printf("\nx : %d, y : %d, z : %d\n", n->x, n->y, n->z);
		ft_printf("adr : %p\n", n);
		ft_printf("up : %p, lft : %p\n", n->up, n->lft);
		ft_printf("col : %p\n", n->col);
		n = n->next;
	}
}

void	print_info_map(t_map *map)
{
	ft_printf("\n\ntitle : %s\n", map->title);
	ft_printf("path : %s\n", map->path);
	ft_printf("y size : %d\n", map->size_y);
	ft_printf("x size : %d\n", map->size_x);
	ft_printf("z min : %d\n", map->z_min);
	ft_printf("z max : %d\n", map->z_max);
	ft_printf("is col : %d\n", map->is_col);
	print_info_list(*(map->point));
}
