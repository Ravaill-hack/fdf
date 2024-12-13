/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:09:22 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:50:14 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	locates the first occurrence of the null-terminated string s2 in the string
//	s1, where not more than n characters are searched. Characters that appear
//	after a ‘\0’ character are not searched.
//	If s2 is empty, s1 is returned
//	If s2 is not found, return NULL, otherwize return pointer to the first
//	occurence of the first character of s2

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	lens2;

	i = 0;
	j = 0;
	lens2 = ft_strlen(s2);
	if (lens2 == 0)
		return ((char *)&s1[0]);
	while ((i < n) && (s1[i] != '\0'))
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while ((s1[i + j] == s2[j]) && ((i + j) < n))
			{
				if ((j + 1) == lens2)
					return ((char *)&s1[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[15];
	char str2[5];

	strcpy(str1, "Je vais bien");
	strcpy(str2, "var");
	printf("%p\n", str1);
	printf("%p\n", ft_strnstr(str1, str2, 15));	
}
*/