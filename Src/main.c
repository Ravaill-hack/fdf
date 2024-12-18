/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 15:49:30 by lmatkows         ###   ########.fr       */
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
	t_point	**nodes;

	if(argc == 2)
	{
		mlx_ptr = mlx_init();
		size_x = 2000;
		size_y = 1500;
		map = get_map(argv[1]);
		win_ptr = mlx_new_window(mlx_ptr, map->win_x, map->win_y, "Test");
		nodes = create_list(map, mlx_ptr, win_ptr);
		set_points(map, nodes);
		//print_info_map(map);	
		//ft_printf("adr mlx : %p\n", mlx_ptr);
		//ft_printf("adr win : %p\n\n", win_ptr);
		//print_info_list(*nodes);
		lines(*nodes);
		mlx_key_hook(win_ptr, do_sth, (void *)(nodes));
		mlx_loop(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		ft_free_tab_i(map);
		ft_free_nodes(nodes);
	}
}
