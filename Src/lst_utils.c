/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:12 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/18 11:20:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_point	*fdf_lstlast(t_point *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	fdf_lstadd_right(t_point **points, t_point *new)
{
	if (!new)
		return;
	if (!(*points))
		*points = new;
	else
		fdf_lstlast(*points)->next = new;
}

t_point	*get_current(t_point *lst)
{
	lst = lst->next;
	if(lst)
		return (lst);
	else
		return (NULL);
}

