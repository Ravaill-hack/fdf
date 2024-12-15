/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/15 20:53:16 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Specifie qu'un appui sur la touche Esc permet de quitter le programme */

t_draw	*init_param(void *mlx_ptr, void *win_ptr)
{
	t_draw	*param;

	param = malloc(sizeof(t_draw));
	param->p_mlx = mlx_ptr;
	param->p_win = win_ptr;
	param->x = 500;
	param->y = 500;
	param->col = 0xFFFFFF;
	param->i = 0;
	param->thick = 20;
	return (param);
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

int	ft_count_lines(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	**fill_char_tab(char *map_t)
{
	char	**tab;
	char	*temp;
	int		nb_lines;
	int		fd;
	int		i;

	nb_lines = get_len_file(map_t);
	i = 0;
	temp = NULL;
	tab = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	fd = open(map_t, O_RDONLY);
	while (i < nb_lines)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break;
		tab[i] = malloc((ft_strlen(temp) + 1) * sizeof(char));
		tab[i] = ft_strdup(temp);
		tab[i][ft_strlen(temp)] = '\0';
		free(temp);
		i++;
	}
	close (fd);
	tab[i] = NULL;
	return (tab);
}

int	**fill_int_tab(char **tab_s)
{
	int		**tab_i;
	int		nb_lines;
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_lines = ft_count_lines(tab_s);
	tab_i = (int **)malloc(sizeof(int *) * nb_lines);
	while (i < nb_lines)
	{
		temp = ft_split(tab_s[i], ' ');
		tab_i[i] = malloc(sizeof(int) * ft_count_lines(temp));
		j = 0;
		while (temp[j] != NULL)
		{
			tab_i[i][j] = ft_atoi(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	return (tab_i);
}

t_map *get_map(char *path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->map = fill_int_tab(fill_char_tab(path));
	map->path = path;
	return (map);
}


int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	void	*win_ptr;
	t_map	*map;
	t_draw	*param;

	(void) argc;
	(void) argv;
	mlx_ptr = mlx_init();
	size_x = 1000;
	size_y = 1000;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Test");
	param = init_param(mlx_ptr, win_ptr);
	map = get_map("Maps/test_maps/10-2.fdf");
	mlx_key_hook(win_ptr, do_sth, (void *)param);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free(param);
	free(map);
}
