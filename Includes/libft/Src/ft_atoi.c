/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:05:39 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:46:17 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The  atoi() function converts the initial portion of the string pointed to
//	by nptr to int. atoi() does not detect errors.
//	RETURN VALUE : the converted value or 0 on error.

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - 48;
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