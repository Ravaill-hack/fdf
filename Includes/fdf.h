/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 17:12:33 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/Includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_libx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sl;
	int		edn;
	int		*image;
}	t_libx;

typedef struct s_map
{
	char	*title;
	char	*path;
	int		**map;
	int		**col;
	int		size_x;
	int		size_y;
	int		win_x;
	int		win_y;
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
	int				xp;
	int				yp;
	int				zp;
	int				col;
	int				i;
	int				thick;
}	t_point;

typedef struct s_line
{
	int		x;
	int		y;
	int		p;
	int		i;
}	t_line;

/*
	Fonctions auxiliaires
*/
int		get_len_file(char *map_t);
int		ft_count_words(char **str);
/*
	Fonctions de debuggage
*/
void	print_info_list(t_point *nodes);
void	print_info_map(t_map *map);
/*
	Fonctions pour initialiser le projet
*/
t_point	*init_param(void *mlx_ptr, void *win_ptr);
t_libx	*init_ptr(t_map *map);
char	*get_title(char *path);
/*
	Fonctions pour parser la carte
*/
char	**fill_char_tab(char *map_t);
int		**fill_int_tab(char **tab_s);
int		**fill_col_tab(char **tab_s);
t_map 	*get_map(char *path);
t_point	*fdf_lstlast(t_point *lst);
void	fdf_lstadd_right(t_point **points, t_point *new);
t_point	**create_list(t_map *map, void *mlx_p, void *win_p);
t_point	*get_current(t_point *lst);
void	fill_points(t_map *map, t_point **points);
t_point	*find_up(t_point *point, t_point *first);
t_point	*find_dow(t_map *map, t_point *point, t_point *first);
t_point	*find_lft(t_point *point, t_point *first);
t_point	*find_rgt(t_map *map, t_point *point, t_point *first);
void	find_neighbours(t_map *map, t_point **points);
int		ext_col_up(char *str, int i);
int		ext_col_low(char *str, int i);
int		ext_col(char *str);
/*
	Fonctions pour creer l'image
*/
void	set_image(t_libx *ptr, t_map *map, t_point **nodes);
/*
	Fonctions pour modifier l'affichage des noeuds
*/
int		set_default_zoom(t_map *map);
double	set_default_zz(t_map *map);
int		x_off(t_map *map, int zo);
int		y_off(t_map *map, int zo);
void	set_points(t_map *map, t_point **points);
void	set_zoom(t_point **points, double zoom);
double	find_z_min(t_map *map);
double	find_z_max(t_map *map);
/*
	Fonctions pour gerer les evenements
*/
void	chose_color(t_point *param, int i);
int		do_sth(int keycode, t_point **nodes);
void	lines(t_point *nodes);
void	zoom(int keycode, t_point **nodes);
void	move(int keycode, t_point **nodes);
void	move_up(t_point **nodes);
void	move_dow(t_point **nodes);
void	move_lft(t_point **nodes);
void	move_rgt(t_point **nodes);
/*
	Fonctions pour dessiner des lignes
*/
int		draw_line(t_point *p1, t_point *p2);
void	draw_vertical_line(t_point *p1, t_point *p2);
void	draw_horizontal_line(t_point *p1, t_point *p2);
void	draw_other_line(t_point *p1, int dx, int dy);
void	draw_other_line_rev(t_point *p1, int dx, int dy);
/*
	Fonctions pour free et delete
*/
void	ft_free_tab_c(char **str);
void	ft_free_tab_i(t_map *map);
void	ft_free_nodes(t_point **nodes);
void	ft_free_all(void *p_mlx, t_map *map, t_point **nodes);
void	finish_process(t_libx *ptr, t_map *map, t_point **nodes);

#endif