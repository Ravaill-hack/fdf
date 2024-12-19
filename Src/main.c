/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 16:42:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/*
Fonctions de debuggage :
		print_info_map(map);	
		print_info_list(*nodes);
*/

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_point	**nodes;

	if (argc == 2)
	{
		map = get_map(argv[1]);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, map->win_x, map->win_y, "Test");
		nodes = create_list(map, mlx_ptr, win_ptr);
		set_points(map, nodes);
		lines(*nodes);
		mlx_key_hook(win_ptr, do_sth, (void *)(nodes));
		mlx_loop(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		mlx_destroy_display(mlx_ptr);
		ft_free_all(mlx_ptr, map, nodes);
	}
}
