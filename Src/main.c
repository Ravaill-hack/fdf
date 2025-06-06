/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:54:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/02/11 14:08:13 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/*
Debuggage :
		print_info_map(var->map);	
*/

int	main(int argc, char **argv)
{
	t_var	*var;

	ft_put_message();
	if (argc == 2)
	{
		ft_putstr_fd("Veuillez patienter. Pourquoi ne pas en profiter", 1);
		ft_putstr_fd(" pour aller prendre un cafe?\n", 1);
		var = init_var(argv[1]);
		init_image(var);
		mlx_put_image_to_window(var->mlx_p, var->win_p, var->img->im_p, 0, 0);
		mlx_hook(var->win_p, 17, 0, ft_close_n_free, (void *)var);
		mlx_key_hook(var->win_p, do_sth, (void *)var);
		mlx_loop_hook(var->mlx_p, do_sth, (void *)var);
		mlx_loop(var->mlx_p);
	}
	else
	{
		ft_putstr_fd("Error : wrong number of arguments", 2);
		return (0);
	}
}
