/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:41:08 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:01 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Cree un nouvel element de type t_list initialise avec la valeur content

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	puts((char *)(ft_lstnew("Je vais bien"))->content);
	puts((char *)(ft_lstnew(""))->content);
	puts((char *)(ft_lstnew("Ahhhhhhhhhhhhhhh"))->content);
} 
*/