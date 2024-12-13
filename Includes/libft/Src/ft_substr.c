/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:31:38 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:50:28 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Alloue avec malloc et retourne une chaine de caracteres issue de s,
//	commencant a start et de longueur maximale len.
//	Renvoie la nouvelle chaine ou NULL si l'allocation echoue.

char	*ft_substr(char	const *s, unsigned int start, size_t	len)
{
	size_t	lenstr;
	size_t	lenalloc;
	size_t	i;
	char	*tab;

	lenstr = 0;
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[(size_t)start + lenstr] != '\0')
		lenstr++;
	if (len >= lenstr)
		lenalloc = lenstr;
	if (len < lenstr)
		lenalloc = len ;
	tab = malloc((lenalloc + 1) * sizeof(char));
	if (tab == 0)
		return (NULL);
	while (i < lenalloc)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{
	puts(ft_substr("je vais bien", 6, 154545454542));
}
*/