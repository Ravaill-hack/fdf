/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 17:19:19 by lmatkows         ###   ########.fr       */
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

int	get_len_file(char *map_t)
{
	int		fd;
	int		nb_lines;
	int		c;
	char	*temp;

	nb_lines = 0;
	c = 0;
	fd = open(map_t, O_RDONLY);
	temp = NULL;
	while (temp != NULL || c == 0)
	{
		temp = get_next_line(fd);
		nb_lines++;
		free(temp);
		c = 1;
	}
	close (fd);
	return (nb_lines);
}

char	**get_map_1(char *map_t)
{
	char	**tab;
	char	*temp;
	int		nb_lines;
	int		fd;
	int		i;

	nb_lines = get_len_file(map_t);
	i = 0;
	temp = NULL;
	tab = malloc(sizeof(char *) * nb_lines);
	fd = open(map_t, O_RDONLY);
	while (i < nb_lines)
	{
		temp = get_next_line(fd);
		tab[i] = malloc(ft_strlen(temp) * sizeof(int));
		tab[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	close (fd);
	tab[i] = NULL;
	return (tab);
}

int	**get_map(char *map_t)
{
	char	**tab_s;
	int		nb_lines;
	char	**tab_i;
	char	**temp;ft_lock
	
	int		fd;

	nb_lines = get_len_file(map_t);
	fd = open(map_t, O_RDONLY);
	while (i < nb_lines)
	{
		temp = get_next_line(fd);
		tab[i] = malloc(ft_strlen(temp) * sizeof(int));
		tab[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	close(fd);
	return (tab_i);
}

int	main(void)
{
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	void	*win_ptr;
	int		**map_i;
	char	*map_t;
	t_draw	*param;

	mlx_ptr = mlx_init();
	size_x = 1000;
	size_y = 1000;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Test");
	param = malloc(sizeof(t_draw));
	map_t = ft_strdup("../Maps/test_maps/10-2.fdf");
	map_i = get_map(map_t);
	init_param(param, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, do_sth, (void *)param);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free(param);
}