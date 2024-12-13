/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:32:39 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:46 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Applique la fonction ’f’ à chaque caractère de la chaîne de caractères
//	transmise comme argument, et en passant son index comme premier argument.
//	Chaque caractère est transmis par adresse à ’f’ afin d’être modifié si
//	nécessaire.
//	Ne renvoie rien, modifie directement la chaine de caracteres s

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
