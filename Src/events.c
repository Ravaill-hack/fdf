/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 15:42:12 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	chose_color(t_point *param, int i)
{
	if (i % 4 == 0)
		param->col = 0x42AAFF;
	else if (i % 4 == 1)
		param->col = 0xFF482B;
	else if (i % 4 == 2)
		param->col = 0x79BD7C;
	else if (i % 4 == 3)
		param->col = 0xD9BF16;
}

int	draw_group(t_point *n)
{
	int		i;
	int		j;
	int		thk;

	thk = n->thick;
	i = -1 * (thk / 2);
	j = i;
	while (i <= (thk / 2))
	{
		j = -1 * (thk / 2);
		while (j <= (thk / 2))
		{
			chose_color(n, n->i);
			mlx_pixel_put(n->p_mlx, n->p_win, n->x + i, n->y + j, n->col);
			j++;
		}
		i++;
	}
	return (0);
}

void	lines(t_point *nodes)
{
	t_point*	a;

	a = nodes;
	while (a)
	{
		if(a->rgt != NULL)
			draw_line(a, a->rgt);
		if(a->dow != NULL)
			draw_line(a, a->dow);
		a = a->next;
	}
}

int	do_sth(int keycode, void *param)
{
	t_point	*nodes;

	nodes = (t_point *)param;
	if (keycode == 65307)
	{
		mlx_loop_end(nodes->p_mlx);
		return (0);
	}
	//mlx_clear_window(n->p_mlx, n->p_win);
	//chose_color(n, n->i);
	//mlx_pixel_put(n->p_mlx, n->p_win, n->x, n->y, n->col);
	//draw_group(n);
	//draw_line(nodes, nodes->next);
	lines(nodes);
	//n->i += 1;
	return (0);
}

