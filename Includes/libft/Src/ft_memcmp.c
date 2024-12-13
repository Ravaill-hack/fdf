/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:58:00 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:09 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  memcmp()  function compares the first n bytes (each interpreted as
//	unsigned char) of the memory areas s1 and s2.
//	The memcmp() function returns  an  integer  less  than,  equal  to,  or
//	greater than zero if the first n bytes of s1 is found, respectively, to
//	be less than, to match, or be greater than the first n bytes of s2.
//	For a nonzero return value, the sign is determined by the sign  of  the
//	difference  between  the  first  pair of bytes (interpreted as unsigned
//	char) that differ in s1 and s2. If n is zero, the return value is zero.

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n - 1))
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	str1[15];
	char	str2[15];
	char 	str3[15];
	strcpy(str1, "Je vais bien");
	strcpy(str2, "Je vbis bien");
	strcpy(str3, "");
	printf("%d\n",ft_memcmp(str1, str3, 5));
	printf("%d\n",ft_memcmp(str1, str2, 4));
}
*/