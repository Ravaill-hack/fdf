/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:01:04 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 16:09:40 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*init_param(void *mlx_ptr, void *win_ptr)
{
	t_point	*param;

	param = (t_point *)malloc(sizeof(t_point));
	if (!param)
		return (NULL);
	param->p_mlx = mlx_ptr;
	param->p_win = win_ptr;
	param->next = NULL;
	param->up = NULL;
	param->dow = NULL;
	param->lft = NULL;
	param->rgt = NULL;
	param->x = 0;
	param->y = 0;
	param->z = 0;
	param->xp = 0;
	param->yp = 0;
	param->zp = 0;
	param->col = 0xFFFFFF;
	param->i = 0;
	param->thick = 20;
	return (param);
}

char	*get_title(char *path)
{
	char	*title;
	char	**temp;
	int		i;

	i = 0;
	title = NULL;
	temp = ft_split(path, '/');
	if (!temp)
		return (NULL);
	while (temp[i] != NULL)
		i++;
	if (i > 0)
		title = ft_strdup(temp[i - 1]);
	ft_free_tab_c(temp);
	return (title);
}

t_libx	*init_ptr(t_map *map)
{
	t_libx *tab;

	tab = (t_libx *)malloc(sizeof(t_libx));
	tab->mlx = mlx_init();
	tab->win = mlx_new_window(tab->mlx, map->win_x, map->win_y, "Test");
	//tab->img = mlx_new_image(tab->mlx, map->win_x, map->win_y);
	//tab->adr_img = mlx_get_data_addr(tab->img, tab->bpp, tab->sl, tab->edn);
	tab->img = NULL;
	tab->adr_img = NULL;
	tab->bpp = NULL;
	tab->sl = NULL;
	tab->edn = NULL;
	return (tab);
}

