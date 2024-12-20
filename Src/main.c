/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 16:36:54 by lmatkows         ###   ########.fr       */
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
	t_libx	*ptr;
	t_map	*map;
	t_point	**nodes;

	if (argc == 2)
	{
		map = get_map(argv[1]);
		ptr = init_ptr(map);
		nodes = create_list(map, ptr->mlx, ptr->win);
		set_points(map, nodes);
		set_image(ptr, map, nodes);
		lines(*nodes);
		mlx_key_hook(ptr->win, do_sth, (void *)(nodes));
		mlx_loop(ptr->mlx);
		finish_process(ptr, map, nodes);
	}
}
