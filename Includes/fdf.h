/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:42 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "libft/Includes/libft.h"

typedef struct s_draw
{
	void	*p_mlx;
	void	*p_win;
	int		x;
	int		y;
	int		col;
	int		i;
	int		thick;
}	t_draw;

#endif