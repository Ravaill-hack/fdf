/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/16 15:15:16 by lmatkows         ###   ########.fr       */
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

int	do_sth(int keycode, void *param)
{
	t_point	*n;

	n = (t_point *)param;
	if (keycode == 65307)
	{
		mlx_loop_end(n->p_mlx);
		return (0);
	}
	if (keycode == 65362)
		n->y -= n->thick;
	else if (keycode == 65364)
		n->y += n->thick;
	else if (keycode == 65361)
		n->x -= n->thick;
	else if (keycode == 65363)
		n->x += n->thick;
	ft_putchar('c');
	//mlx_clear_window(n->p_mlx, n->p_win);
	//chose_color(n, n->i);
	//mlx_pixel_put(n->p_mlx, n->p_win, n->x, n->y, n->col);
	draw_group(n);
	n->i += 1;
	return (0);
}

