/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:24 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/20 15:35:06 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_image(t_libx *ptr, t_map *map, t_point **nodes)
{
	(void) map;
	(void) nodes;
	ptr->adr_img = mlx_get_data_addr(ptr->img, ptr->bpp, ptr->sl, ptr->edn);
}
