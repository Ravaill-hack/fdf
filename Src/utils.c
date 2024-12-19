/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:06:09 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 16:26:04 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	get_len_file(char *map_t)
{
	int		fd;
	int		nb_lines;
	int		c;
	char	*temp;

	nb_lines = 0;
	c = 0;
	fd = open(map_t, O_RDONLY);
	temp = NULL;
	while (temp != NULL || c == 0)
	{
		temp = get_next_line(fd);
		nb_lines++;
		free(temp);
		c = 1;
	}
	close (fd);
	if (nb_lines == 0)
		return (0);
	else
		return (nb_lines - 1);
}

int	ft_count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
