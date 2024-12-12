/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/12 11:29:17 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Specifie qu'un appui sur la touche Esc permet de quitter le programme */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_param(t_draw *param, void *mlx_ptr, void *win_ptr)
{
	param->p_mlx = mlx_ptr;
	param->p_win = win_ptr;
	param->x = 500;
	param->y = 500;
	param->col = 0xFFFFFF;
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
		n->y -= 10;
	else if (keycode == 65364)
		n->y += 10;
	else if (keycode == 65361)
		n->x -= 10;
	else if (keycode == 65363)
		n->x += 10;
	ft_putchar('c');
	mlx_clear_window(n->p_mlx, n->p_win);
	mlx_pixel_put(n->p_mlx, n->p_win, n->x, n->y, n->col);
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