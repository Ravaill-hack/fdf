/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:12:12 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat de la
//	concaténation de s1 et s2.

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*tab;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	tab = malloc((lens1 + lens2 +1) * sizeof(char));
	if (tab == 0)
		return (NULL);
	while (i < (lens1))
	{
		tab[i] = s1[i];
		i++;
	}
	while (i < (lens1 + lens2))
	{
		tab[i] = s2[i - lens1];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{
	puts(ft_strjoin("Je vais", " bien"));
	puts(ft_strjoin("", ""));
}
*/
