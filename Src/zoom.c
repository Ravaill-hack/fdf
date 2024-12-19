/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:59:44 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 11:42:10 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	zoom(int keycode, t_point **nodes)
{
	if (keycode == XK_KP_Add)
	{
		set_zoom(nodes, 1.1);
		mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
		lines(*nodes);
	}
	if (keycode == XK_KP_Subtract)
	{
		set_zoom(nodes, 0.9);
		mlx_clear_window((*nodes)->p_mlx, (*nodes)->p_win);
		lines(*nodes);
	}
}
