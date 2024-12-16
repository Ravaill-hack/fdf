/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/16 21:26:21 by Lmatkows         ###   ########.fr       */
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
	void			*p_mlx;
	void			*p_win;
	struct s_point	*next;
	struct s_point	*up;
	struct s_point	*dow;
	struct s_point	*lft;
	struct s_point	*rgt;
	int				x;
	int				y;
	int				z;
	int				col;
	int				i;
	int				thick;
}	t_point;

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
t_point	*fdf_lstlast(t_point *lst);
void	fdf_lstadd_right(t_point **points, t_point *new);
t_point	**create_list(t_map *map, void *mlx_p, void *win_p);
t_point	*get_current(t_point *lst);
void	fill_points(t_map *map, t_point **points);
t_point	*find_up(t_map *map, t_point *point, t_point *first);
t_point	*find_dow(t_point *point, t_point *first);
t_point	*find_lft(t_point *point, t_point *first);
t_point	*find_rgt(t_map *map, t_point *point, t_point *first);
void	find_neighbours(t_map *map, t_point **points);
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