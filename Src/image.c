/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 17:32:04 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_image(t_libx *ptr, t_map *map, t_point **nodes)
{
	int	x0;
	int	y0;

	(void) map;
	(void) nodes;
	x0 = 0;
	y0 = 0;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, x0, y0);
}
