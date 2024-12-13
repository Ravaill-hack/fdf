/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:25:20 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:42 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	ajoute l'element new au debut de la liste
//	1. il faut definir que l'element next de new est l'ancien premier
//	element (lst)
//	2. il faut modifier l'adresse du premier element de la liste, qui prend
//	l'adresse du nouvel element (new)

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst01;
	t_list	*lst02;

	lst01 = malloc(sizeof(t_list));
	lst01->content = "Et toi";
	lst01->next = NULL;
	lst = &lst01;
	lst02 = (ft_lstnew("Je vais bien"));
	ft_lstadd_front(lst, lst02);
	while (*lst != NULL)
	{
		puts((char *)((*lst)->content));
		*lst = (*lst)->next;
	}
} 
*/