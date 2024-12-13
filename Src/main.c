/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 11:33:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Specifie qu'un appui sur la touche Esc permet de quitter le programme */

void	init_param(t_draw *param, void *mlx_ptr, void *win_ptr)
{
	param->p_mlx = mlx_ptr;
	param->p_win = win_ptr;
	param->x = 500;
	param->y = 500;
	param->col = 0xFFFFFF;
	param->i = 0;
	param->thick = 20;
}

void	chose_color(t_draw *param, int i)
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

int	draw_group(t_draw *n)
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
	t_draw	*n;

	n = (t_draw *)param;
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

int	main(void)
{
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	void	*win_ptr;
	t_draw	*param;

	mlx_ptr = mlx_init();
	size_x = 1000;
	size_y = 1000;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Test");
	param = malloc(sizeof(t_draw));
	init_param(param, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, do_sth, (void *)param);
	mlx_loop(mlx_ptr);
}