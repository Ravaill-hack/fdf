/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/16 15:15:44 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "libft/Includes/libft.h"

typedef struct s_map
{
	char	*title;
	char	*path;
	int		**map;
	int		size_x;
	int		size_y;
}	t_map;

typedef struct s_point
{
	void	*p_mlx;
	void	*p_win;
	int		x;
	int		y;
	int		z;
	int		col;
	int		i;
	int		thick;
}	t_point;

typedef struct s_nodes
{
	t_point			*points;
	struct s_nodes	*up;
	struct s_nodes	*dow;
	struct s_nodes	*lft;
	struct s_nodes	*rgt;
}	t_nodes;

/*
	Fonctions auxiliaires
*/
int		get_len_file(char *map_t);
int		ft_count_lines(char **str);
/*
	Fonctions pour initialiser le projet
*/
t_point	*init_param(void *mlx_ptr, void *win_ptr);
char	*get_title(char *path);
/*
	Fonctions pour parser la carte
*/
char	**fill_char_tab(char *map_t);
int		**fill_int_tab(char **tab_s);
t_map 	*get_map(char *path);
/*
	Fonctions pour gerer les evenements
*/
void	chose_color(t_point *param, int i);
int		draw_group(t_point *n);
int		do_sth(int keycode, void *param);
/*
	Fonctions pour dessiner des lignes
*/
int		draw_line(t_point *p1, t_point *p2);
int		draw_vertical_line(t_point *p1, t_point *p2);
int		draw_horizontal_line(t_point *p1, t_point *p2);
int		draw_other_line(t_point *p1, t_point *p2, int dx, int dy);
int		draw_other_line_rev(t_point *p1, t_point *p2, int dx, int dy);
/*
	Fonctions pour free et delete
*/
void	ft_free_tab_c(char **str);
void	ft_free_tab_i(t_map *map);

#endif