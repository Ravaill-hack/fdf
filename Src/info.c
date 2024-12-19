/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:16 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 15:27:35 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	print_info_list(t_point *n)
{
	while (n)
	{
		ft_printf("\nx : %d, y : %d, z : %d\n", n->x, n->y, n->z);
		ft_printf("p_mlx : %p\n", n->p_mlx);
		ft_printf("p_win : %p\n", n->p_win);
		ft_printf("adr : %p\n", n);
		ft_printf("up : %p, down : %p, ", n->up, n->dow);
		ft_printf("left : %p, right : %p\n", n->lft, n->rgt);
		n = n->next;
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
			ft_printf("%d ", map->col[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}
