/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:00 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:10 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	ft_free_tab_c(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_free_tab_i(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->map[i]);
		free(map->col[i]);
		map->map[i] = NULL;
		map->col[i] = NULL;
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map->col);
	map->col = NULL;
	free(map->title);
	map->title = NULL;
	free(map);
	map = NULL;
}

void	ft_free_nodes(t_point **nodes)
{
	t_point	*temp;

	temp = *nodes;
	while (*nodes)
	{
		temp = (*nodes)->next;
		free(*nodes);
		*nodes = NULL;
		*nodes = temp;
	}
	free(nodes);
}

void	ft_free_all(void *p_mlx, t_map *map, t_point **nodes)
{
	free(p_mlx);
	ft_free_tab_i(map);
	ft_free_nodes(nodes);
}
