/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:03 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Compte le nombre d'elements dans la liste lst

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i ++;
	}
	return (i);
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
	printf("%d\n",ft_lstsize(*lst));
}
*/
