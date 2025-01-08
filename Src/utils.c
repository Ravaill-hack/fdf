/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:26:20 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/07 17:12:27 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ft_count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	*get_title(const char *path)
{
	char	*title;
	char	**temp;
	int		i;

	i = 0;
	title = NULL;
	temp = ft_split(path, '/');
	if (!temp)
		return (NULL);
	while (temp[i] != NULL)
		i++;
	if (i > 0)
		title = ft_strdup(temp[i - 1]);
	ft_free_tab_c(temp);
	return (title);
}

t_point	*get_next(t_point *node)
{
	node = node->next;
	if (node)
		return (node);
	return (NULL);
}

char	*ft_hex_itoa(int col, char *base)
{
	char	*hex;
	int		i;

	i = 5;
	hex = (char *)malloc(sizeof(char) * 7);
	hex[6] = '\0';
	while (i >= 0)
	{
		hex[i] = base[col % 16];
		col = col / 16;
		i--;
	}
	return (hex);
}

int	find_i(char c, char *base)
{
	int	i;

	i = 0;
	while (i <= 16)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
