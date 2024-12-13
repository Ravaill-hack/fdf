/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:48:04 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:15 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The memmove() function copies n bytes from memory area src to memory area
//	dest. The memory areas may overlap.

void	*ft_memmove(void	*dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*strd;
	const unsigned char	*strs;

	strd = (unsigned char *)dest;
	strs = (const unsigned char *)src;
	if (strd < strs && len != 0)
	{
		i = 0;
		while (i < len)
		{
			strd[i] = strs[i];
			i++;
		}
	}
	else if (strd > strs && len != 0)
	{
		i = len;
		while (i > 0)
		{
			strd[i - 1] = strs[i - 1];
			i--;
		}
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
	ft_memmove(src + 2, src, 2);
	puts(dest);
	puts(src);
}
*/
