/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:00 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/09 10:59:16 by lmatkows         ###   ########.fr       */
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

int	ft_close_n_free(void *v)
{
	t_var	*var;

	var = (t_var *)v;
	ft_close_aff(var);
	ft_free_img_n_map(var->img, var->map);
	free(var->mlx_p);
	var->mlx_p = NULL;
	free(var);
	var = NULL;
	exit(0);
	return (0);
}

void	ft_free_img_n_map(t_img *img, t_map *map)
{
	free(img);
	img = NULL;
	free(map->title);
	map->title = NULL;
	free(map->path);
	map->path = NULL;
	ft_free_nodes(map->point);
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
	nodes = NULL;
}

void	ft_close_aff(t_var *var)
{
	mlx_destroy_image(var->mlx_p, var->img->im_p);
	mlx_destroy_window(var->mlx_p, var->win_p);
	mlx_destroy_display(var->mlx_p);
}
