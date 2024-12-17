/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:31 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/17 13:48:01 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	lines(t_point *nodes)
{
	t_point*	a;

	a = nodes;
	while (a)
	{
		if(a->rgt != NULL)
			draw_line(a, a->rgt);
		if(a->dow != NULL)
			draw_line(a, a->dow);
		a = a->next;
	}
}
