/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:43:38 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:37:08 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ext_col(char *str, int i)
{
	char	*color;
	int		nb;

	color = ft_substr(str, (unsigned)i + 2, 6);
	nb = ft_atoi_base(color, "0123456789ABCDEF");
	free (color);
	color = NULL;
	return (nb);
}
