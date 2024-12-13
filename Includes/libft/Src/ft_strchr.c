/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:35:26 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:40 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The strchr() function returns a pointer to the first occurrence of the
//	character c in the string s.

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != (unsigned char)c))
		i++;
	if (s[i] == '\0' && (unsigned char)c != 0)
		return (NULL);
	return ((char *)&s[i]);
}

/*
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char	str[] = "abcdefghijklmno";
	printf("%p\n", str);
	printf("%p\n", ft_strchr(str, 'a'));
}
*/