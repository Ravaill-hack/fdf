/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:55:22 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:12 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  memcpy()  function  copies  n bytes from memory area src to memory
//	area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
//	memory areas do overlap.
// 	Cela veut dire que si les 2 zones se chevauchent, l'une ecrase l'autre.
//	Returns a pointer to dest.

void	*ft_memcpy(void	*dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*strd;
	const unsigned char	*strs;

	i = 0;
	strd = (unsigned char *)dest;
	strs = (const unsigned char *)src;
	if (len == 0 || dest == src)
		return (dest);
	while (i < len)
	{
		strd[i] = strs[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[15];
	char	src[15];
	strcpy(dest, "Test test");
	strcpy(src, "Canaille");
	puts(dest);
	puts(src);
	ft_memcpy(dest, src, 2);
	puts(dest);
	puts(src);
}
*/