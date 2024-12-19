/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:50:47 by lmatkows         ###   ########.fr       */
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

void	lines(t_point *nodes)
{
	t_point	*a;

	a = nodes;
	while (a)
	{
		if (a->rgt != NULL)
			draw_line(a, a->rgt);
		if (a->dow != NULL)
			draw_line(a, a->dow);
		a = a->next;
	}
}

int	do_sth(int keycode, t_point **nodes)
{
	if (keycode == 65307)
	{
		mlx_loop_end((*nodes)->p_mlx);
		return (0);
	}
	move(keycode, nodes);
	zoom(keycode, nodes);
	return (0);
}
