/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:32:32 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:48 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Libere la memoire de l'element passe en argument en utilisant la fonction
//	del, puis avec free. la memoire de next ne doit pas etre free

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((lst)->content);
	free (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	del_test(void *element)
{
	free(element);
}

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
	puts(lst03->content);
	ft_lstdelone(lst03, del_test);
	puts(lst03->content);
}
*/