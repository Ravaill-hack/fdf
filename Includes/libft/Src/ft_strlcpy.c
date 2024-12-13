/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:20:19 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:59 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The strlcpy() function copies up to size - 1 characters from the NUL
//	-terminated string src to dst, NUL-terminating the result.
//	Returns the total length of the string it tries to create, i.e. the
//	length of src.

size_t	ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (ft_strlen(src));
	while ((i < len - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	src[] = "Test 1 2 1 2";
	char	dest[] = "Valeur a ecraser";

	puts(src);
	puts(dest);
	ft_strlcpy(dest, src, 2);
	puts(dest);
}
*/