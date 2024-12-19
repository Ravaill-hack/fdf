/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:01:04 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 15:16:26 by lmatkows         ###   ########.fr       */
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
