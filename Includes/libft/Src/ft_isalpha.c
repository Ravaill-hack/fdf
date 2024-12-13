/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:44 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:12 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	These  functions  check  whether c falls into a certain character class
//	according  to the  specified  locale.   The functions without the "_l
//	suffix perform the check based on the current locale.

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	int	c1;
	int	c2;

	c1 = 49;
	c2 = 67;
	printf("%d\n", ft_isalpha(c1));
	printf("%d\n", ft_isalpha(c2));
}
*/