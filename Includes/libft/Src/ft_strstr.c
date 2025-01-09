/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:09:22 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:39:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	locates the first occurrence of the null-terminated string s2 in the string
//	s1. Characters that appear after a ‘\0’ character are not searched.
//	If s2 is empty, -1 is returned
//	If s2 is not found, return -1, otherwize return the index to the occurence
//	of the first character of s2

int	ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens2;

	i = 0;
	j = 0;
	lens2 = ft_strlen(s2);
	if (lens2 == 0)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j])
			{
				if ((j + 1) == lens2)
					return (i);
				j++;
			}
		}
		i++;
	}
	return (-1);
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