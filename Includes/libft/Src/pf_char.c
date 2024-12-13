/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:22 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 11:09:44 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i ++;
	}
	return (i);
}

int	ft_putadr(void *p)
{
	int				i;
	unsigned long	ptr;

	i = 0;
	ptr = (unsigned long)p;
	if (!p)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	i = i + ft_adrhexa(ptr);
	return (i);
}
