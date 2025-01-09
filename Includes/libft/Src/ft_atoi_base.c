/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:05:39 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:39:30 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  atoi_base() function converts the initial portion of the string
//	pointed to by str to int. atoi() does not detect errors.
//	RETURN VALUE : the converted value or 0 on error.

static int	to_find_c(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	size_t	len;
	size_t	i;
	int		sign;
	int		nb;
	int		ibase;

	i = 0;
	len = ft_strlen(base);
	sign = 1;
	nb = 0;
	ibase = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	while (to_find_c(str[i], base) >= 0)
	{
		ibase = to_find_c(str[i], base);
		nb = nb * len + ibase;
		i++;
	}
	return (nb * sign);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%d\n",ft_atoi("        -45638"));
	printf("%d\n",ft_atoi("        -+45638"));
	printf("%d\n",ft_atoi("        +45638"));
	printf("%d\n",ft_atoi("        45638"));
	printf("%d\n",ft_atoi("34"));
	printf("%d\n",ft_atoi("2147483647"));
	printf("%d\n",ft_atoi("-2147483648"));
}
*/