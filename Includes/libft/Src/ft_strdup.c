/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:48:57 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  strdup()  function returns a pointer to a new string which is a
//	duplicate of the string s.  Memory for the new string is obtained with
//	malloc.

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_strlen((char *)s);
	str = ft_calloc((size_t)len + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *s1 = "Je m'appelle Lucas";
	char *s2;

	s2 = ft_strdup(s1);
	printf("%s\n", s1);
	printf("%s\n", s2);
}
*/