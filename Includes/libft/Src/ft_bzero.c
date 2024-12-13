/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:46:07 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:47:38 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  bzero()  function  erases  the  data  in the n bytes of the memory
//	starting at the location pointed to by s, by writing zeros (bytes  con‐
//	taining '\0') to that area.

void	*ft_bzero(void	*adr, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = adr;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (adr);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[10];
	strcpy(str, "Test test");
	puts(str);
	ft_bzero(str, 0);
	puts(str);
}
*/