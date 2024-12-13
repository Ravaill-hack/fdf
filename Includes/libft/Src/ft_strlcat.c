/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:45:10 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:55 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Concatenate two strings take the full size of the buffer (not just the
//	length) and guarantee to NUL-terminate the result (as long as size is
//	larger than 0 or, in the case of strlcat(), as long as there is at least
//	one byte free in dst).  Note that a byte for the NUL should be included in
//	size. Appends the NUL-terminated string src to the end of dst.  It will
//	append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
//
//	Returns either : 
//	- the initial length of dst plus the length of src
//	- or, if strlcat() traverses size characters without finding a NUL, the
//	length of the string is considered to be size and the destination string
//	will not be NUL-terminated (since there was no space for the NULL).

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	size_t	len_ret;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	len_ret = len_d + len_s;
	if (size <= len_d)
		return (size + len_s);
	while ((src[i] != '\0') && (len_d < (size - 1)))
	{
		dest[len_d] = src[i];
		len_d++;
		i++;
	}
	dest[len_d] = '\0';
	return (len_ret);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	src[] = "Test 1 2 1 2";
	char	dest1[30] = "Valeur a ecraser";
	char	dest2[30] = "Valeur a ecraser";

	puts(src);
	puts(dest1);
	puts(dest2);
	printf("%ld\n",strlcat(dest1, src, 400));
	printf("%d\n",ft_strlcat(dest2, src, 400));
	puts(dest1);
	puts(dest2);
}
*/
