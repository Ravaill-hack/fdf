/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:47:46 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:39 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	ajoute l'element new a la fin de la liste

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst01;
	t_list	*lst02;

	lst01 = (ft_lstnew("Je vais bien"));
	lst = &lst01;
	lst02 = (ft_lstnew("Et toi"));
	ft_lstadd_back(lst, lst02);
	while (*lst != NULL)
	{
		puts((char *)((*lst)->content));
		*lst = (*lst)->next;
	}
} 
*/