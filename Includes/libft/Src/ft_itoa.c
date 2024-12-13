/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:57:19 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:36 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Alloue avec MALLOC et retourne une chaine de caracteres representant
//	l'entier n recu en argument. Les nombres negatifs doivent etre geres.

static size_t	count_char(long int nbint)
{
	size_t	count;

	count = 0;
	if (nbint == 0)
		return (2);
	if (nbint < 0)
	{
		count ++;
		nbint = -nbint;
	}
	while (nbint > 0)
	{
		nbint = nbint / 10;
		count ++;
	}
	return (count + 1);
}

static char	*fill_intchar(long int nbint)
{
	char	*nbchar;
	size_t	i;

	i = count_char(nbint) - 1;
	nbchar = (char *)malloc(count_char(nbint) * sizeof(char));
	if (!nbchar)
		return (NULL);
	nbchar[i] = '\0';
	i--;
	if (nbint == 0)
		nbchar[0] = '0';
	if (nbint < 0)
	{
		nbchar[0] = '-';
		nbint = -nbint;
	}
	while (nbint > 0)
	{
		nbchar[i] = nbint % 10 + 48;
		nbint = nbint / 10;
		i--;
	}
	return (nbchar);
}

char	*ft_itoa(int n)
{
	char		*nbchar;
	long int	nbint;

	nbint = (long int)n;
	nbchar = fill_intchar(nbint);
	return (nbchar);
}
