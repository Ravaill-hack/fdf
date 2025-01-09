/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:15 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/09 12:16:44 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	do_sth(int keyc, t_var *var)
{
	ft_printf("%d\n", keyc);
	if (keyc == 65307)
		ft_close_n_free(var);
	if (keyc == 113 || keyc == 119 || keyc == 97 || keyc == 115
		|| keyc == 122 || keyc == 120)
		ft_rot(var, keyc);
	if (keyc == 111 || keyc == 112)
		ft_zoom(var, keyc);
	if (keyc == 107 || keyc == 108)
		ft_alt(var, keyc);
	if (keyc == 65362 || keyc == 65364 || keyc == 65361 || keyc == 65363)
		ft_trans(var, keyc);
	return (0);
}

int	ft_rot(t_var *var, int keyc)
{
	ft_clear_image(var);
	if (keyc == 113)
		var->att.ang_x += 2;
	if (keyc == 119)
		var->att.ang_x -= 2;
	if (keyc == 97)
		var->att.ang_y += 2;
	if (keyc == 115)
		var->att.ang_y -= 2;
	if (keyc == 122)
		var->att.ang_z += 2;
	if (keyc == 120)
		var->att.ang_z -= 2;
	ft_set_image(var);
	return (0);
}

int	ft_trans(t_var *var, int keyc)
{
	ft_clear_image(var);
	if (keyc == 65362)
		var->att.y0 += 20;
	if (keyc == 65364)
		var->att.y0 -= 20;
	if (keyc == 65361)
		var->att.x0 += 20;
	if (keyc == 65363)
		var->att.x0 -= 20;
	ft_set_image(var);
	return (0);
}

int	ft_zoom(t_var *var, int keyc)
{
	ft_clear_image(var);
	if (keyc == 112)
		var->att.zoom *= 1.1;
	if (keyc == 111)
		var->att.zoom *= 0.91;
	ft_set_image(var);
	return (0);
}

int	ft_alt(t_var *var, int keyc)
{
	ft_clear_image(var);
	if (keyc == 107)
		var->att.fac_z *= 1.1;
	if (keyc == 108)
		var->att.fac_z *= 0.91;
	ft_set_image(var);
	return (0);
}
