/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:05:26 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:50:11 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	compares the n (at most) first n bytes of the two strings s1 and s2. The
//	comparison is done using unsigned characters.
//	Returns 0 if s1 == s2, a negative value if s1 > s2 and a positive value if
//	si > s2.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')
		&& (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("Helalo", "Helblo", 3));
	printf("%d\n", ft_strncmp("Helalo", "Helblo", 5));
}
*/