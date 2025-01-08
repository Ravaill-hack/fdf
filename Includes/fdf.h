/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/08 14:32:07 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X_WIN 1400
# define Y_WIN 900
# define PI 3.14159265358979323846

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/Includes/libft.h"

typedef struct s_att
{
	int		ang_x;
	int		ang_y;
	int		ang_z;
	double	zoom;
	double	fac_z;
	int		x0;
	int		y0;
}	t_att;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				x0;
	int				y0;
	int				z0;
	int				col;
	struct s_point	*next;
	struct s_point	*up;
	struct s_point	*lft;
}	t_point;

typedef struct s_map
{
	char	*title;
	char	*path;
	t_point	**point;
	int		size_x;
	int		size_y;
}	t_map;

typedef struct s_img
{
	void	*im_p;
	int		bp;
	int		sl;
	int		ed;
	char	*im;
}	t_img;

typedef struct s_var
{
	void	*mlx_p;
	void	*win_p;
	t_map	*map;
	t_img	*img;
	t_att	att;
}	t_var;

typedef struct s_line
{
	int		i;
	int		x0;
	int		y0;
	int		p;
}	t_line;

typedef struct s_col
{
	int		R01;
	int		R02;
	int		G01;
	int		G02;
	int		B01;
	int		B02;
	char	*colh1;
	char	*colh2;
	int		R;
	int		G;
	int		B;
}	t_col;

/*
	Fonctions auxiliaires
*/
char	*get_title(const char *path);
t_point	*ft_lst_last(t_point *nodes);
int		ft_count_words(char **str);
t_point	*get_next(t_point *node);
char	*ft_hex_itoa(int col, char *base);
int		find_i(char c, char *base);
/*
	Fonctions de debuggage
*/
void	print_info_list(t_point *nodes);
void	print_info_map(t_map *map);
/*
	Fonctions pour initialiser le projet
*/
t_var	*init_var(const char *path);
t_img	*init_img(void *mlx_p);
t_map 	*init_map(const char *path);
t_att	init_att(void);
/*
	Fonctions pour parser la carte
*/
void	get_map(t_map *map, const char *path);
int		lst_create_n_add(t_point **nodes, char *l, int j);
t_point *ft_new_node(char *str, int i, int j);
void	ft_lst_add_right(t_point **nodes, t_point *elem);
t_point	*find_up(t_point *point, t_point *first);
t_point	*find_lft(t_point *point, t_point *first);
int		ext_col_up(char *str, int i);
int		ext_col_low(char *str, int i);
int		ext_col(char *str);
/*
	Fonctions gerer l'image
*/
void	init_image(t_var *var);
void	draw_image(t_var *var);
void	ft_set_image(t_var *var);
void	ft_clear_image(t_var *var);
/*
	Fonctions pour modifier l'affichage des noeuds
*/
void	ft_set_image(t_var *var);
void	ft_set_alt(t_var *var, double fact);
void	ft_set_zoom(t_var *var, double zoom);
void	ft_set_offset(t_var *var, int x_off, int y_off);
int		ft_set_rot(t_var *var, int ax, int ay, int az);
/*
	Fonctions pour gerer les evenements
*/
int		do_sth(int keyc, t_var *var);
int		ft_alt(t_var *var, int keyc);
int		ft_rot(t_var *var, int keyc);
int		ft_trans(t_var *var, int keyc);
int		ft_zoom(t_var *var, int keyc);
/*
	Fonctions pour dessiner des lignes
*/
int		draw_line(t_var *var, t_point *p1, t_point *p2);
void	draw_vertical_line(t_var *var, t_point *p1, t_point *p2);
void	draw_horizontal_line(t_var *var, t_point *p1, t_point *p2);
void	draw_other_line(t_var *var, t_point *p1, t_point *p2, int dx, int dy);
void	draw_other_line_rev(t_var *var, t_point *p1, t_point *p2, int dx, int dy);
void	draw_point(t_var *var, int x, int y, int col);
int		ft_col(int col1, int col2, int delt, int i);
int		extract_red(char *col, char *base);
int		extract_green(char *col, char *base);
int		extract_blue(char *col, char *base);
/*
	Fonctions pour free et delete
*/
void	ft_free_tab_c(char **str);
int		ft_close_n_free(void *v);
void	ft_free_img(t_img *img);
void	ft_free_map(t_map *map);
void	ft_free_nodes(t_point **nodes);
void	ft_close_aff(t_var *var);

#endif