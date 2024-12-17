/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 16:01:24 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	void	*win_ptr;
	t_map	*map;
	//t_point	*param;
	t_point	**nodes;

	(void) argc;
	(void) argv;
	mlx_ptr = mlx_init();
	size_x = 2000;
	size_y = 1500;
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "Test");
	//param = init_param(mlx_ptr, win_ptr);
	map = get_map("Maps/test_maps/10-2.fdf");
	nodes = create_list(map, mlx_ptr, win_ptr);
	// print_info_map(map);
	//ft_printf("adr mlx : %p\n", mlx_ptr);
	//ft_printf("adr win : %p\n\n", win_ptr);
	//print_info_list(*nodes);
	mlx_key_hook(win_ptr, do_sth, (void *)(*nodes));
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	//free(param);
	ft_free_tab_i(map);
}
