/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:07 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:51:54 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	gnl_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

char	*gnl_substrfrom(char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	while ((str[i] != c) && (str[i] != '\0'))
		i++;
	i = i + ((str[i] == c));
	start = i;
	while (str[i] != '\0')
		i ++;
	dest = (char *)malloc((i - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (str[start] != '\0')
	{
		dest[j] = str[start];
		start ++;
		j ++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*gnl_substrto(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while ((str[i] != c) && (str[i] != '\0'))
		i++;
	dest = (char *)malloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while ((str[i] != '\0') && (str[i] != c))
	{
		dest[i] = str[i];
		i ++;
	}
	if (str[i] == c)
		dest[i] = '\n';
	else
		dest[i] = '\0';
	dest[i + 1] = '\0';
	return (dest);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	char	*ret;

	i = 0;
	if ((s1 == NULL) || (s1[0] == '\0'))
		len1 = 0;
	else
		len1 = gnl_strlen(s1);
	ret = (char *)malloc((len1 + gnl_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (len1 + gnl_strlen(s2)))
	{
		ret[i] = s2[i - len1];
		i ++;
	}
	ret[i] = '\0';
	return (ret);
}
