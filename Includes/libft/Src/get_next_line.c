/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:31:03 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:52:50 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static char	*read_line(int fd, char *buffer, char *tmr)
{
	int		ind;
	char	*temp;
	char	*rawline;

	rawline = tmr;
	ind = 1;
	while (gnl_strchr(rawline, '\n') == -1)
	{
		ind = read(fd, buffer, BUFFER_SIZE);
		if (ind == -1)
			return (NULL);
		if (ind == 0)
			break ;
		buffer[ind] = '\0';
		temp = rawline;
		rawline = gnl_strjoin(rawline, buffer);
		free(temp);
		temp = NULL;
	}
	if (!rawline || rawline[0] == '\0')
		return (NULL);
	return (rawline);
}

char	*get_next_line(int fd)
{
	char		*buffer[1000];
	char		*rawline;
	char		*line;
	static char	*toomuchread[1000] = {NULL};

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer[fd])
		return (NULL);
	rawline = read_line(fd, buffer[fd], toomuchread[fd]);
	free(buffer[fd]);
	buffer[fd] = NULL;
	if (!rawline)
	{
		free(rawline);
		free(toomuchread[fd]);
		toomuchread[fd] = NULL;
		return (NULL);
	}
	line = gnl_substrto(rawline, '\n');
	toomuchread[fd] = gnl_substrfrom(rawline, '\n');
	free(rawline);
	return (line);
}
/*
#include <stdio.h>

int main (void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("Test.txt", O_RDONLY);
	fd2 = open("Test2.txt", O_RDONLY);
	fd3 = open("Test3.txt", O_RDONLY);
	while ((line = get_next_lineb(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_lineb(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_lineb(fd3)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}
*/
