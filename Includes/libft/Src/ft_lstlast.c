/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:40:31 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:54 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	renvoie le dernier element de la liste

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst01;
	t_list	*lst02;
	t_list	*lst03;

	lst03 = (ft_lstnew("Test 3"));
	lst = &lst03;
	lst02 = (ft_lstnew("Test 2"));
	ft_lstadd_front(lst, lst02);
	lst01 = (ft_lstnew("Test 1"));
	ft_lstadd_front(lst, lst01);
	puts((ft_lstlast(*lst))->content);
}
*/