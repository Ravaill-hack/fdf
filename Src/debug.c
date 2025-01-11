/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:16 by Lmatkows          #+#    #+#             */
/*   Updated: 2025/01/11 14:08:35 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	print_info_list(t_point *n)
{
	while (n)
	{
		ft_printf("\nx : %d, y : %d, z : %d\n", n->x, n->y, n->z);
		ft_printf("adr : %p\n", n);
		ft_printf("up : %p, lft : %p\n", n->up, n->lft);
		ft_printf("col : %p\n", n->col);
		n = n->next;
	}
}

void	print_info_map(t_map *map)
{
	ft_printf("\n\ntitle : %s\n", map->title);
	ft_printf("path : %s\n", map->path);
	ft_printf("y size : %d\n", map->size_y);
	ft_printf("x size : %d\n", map->size_x);
	ft_printf("z min : %d\n", map->z_min);
	ft_printf("z max : %d\n", map->z_max);
	ft_printf("is col : %d\n", map->is_col);
	print_info_list(*(map->point));
}

void	ft_put_message(void)
{
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Bienvenue dans FdF, qui va vous permettre d'afficher ", 1);
	ft_putstr_fd("une carte en 3D.\n\nPour executer le programme il ", 1);
	ft_putstr_fd("faut rentrer en argument le chemin de la carte a ", 1);
	ft_putstr_fd("afficher.\n\n Tant que la fenetre est ouverte vous ", 1);
	ft_putstr_fd("pouvez effectuer plusieurs commandes  :\n - zoomer ou", 1);
	ft_putstr_fd(" dezoomer avec les touches o et p\n - deplacer la vue", 1);
	ft_putstr_fd(" avec les fleches du clavier\n - modifier le facteur ", 1);
	ft_putstr_fd("d'altitude avec les touches k et l\n - tourner autour", 1);
	ft_putstr_fd(" de l'axe x avec les touches q et w\n - tourner ", 1);
	ft_putstr_fd("autour de l'axe y avec les touches a et s\n - tourner", 1);
	ft_putstr_fd(" autour de l'axe z avec les touches z et x\n\n", 1);
	ft_putstr_fd("Pour quitter le programme appuyez sur ESC ou cliquez", 1);
	ft_putstr_fd(" sur la croix\n\n", 1);
}
