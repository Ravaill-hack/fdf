/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:57:28 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:22 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	Ecrit le caractere c sur la sortie file descriptor indiquee

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
