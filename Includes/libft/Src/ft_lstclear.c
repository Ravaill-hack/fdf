/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Libere la memoire de tous les elements de la liste avec la fonction del
//	passee en argument puis avec free. L'adresse initiale de la liste devient
//	NULL

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*adr;

	adr = NULL;
	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		adr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = adr;
	}
	*lst = NULL;
}
