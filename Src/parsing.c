/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:03:10 by lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 14:04:34 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

char	**fill_char_tab(char *map_t)
{
	char	**tab;
	char	*temp;
	int		nb_lines;
	int		fd;
	int		i;

	nb_lines = get_len_file(map_t);
	i = 0;
	temp = NULL;
	tab = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	fd = open(map_t, O_RDONLY);
	while (i < nb_lines)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		tab[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	close (fd);
	tab[i] = NULL;
	return (tab);
}

int	**fill_int_tab(char **tab_s)
{
	int		**tab_i;
	int		nb_lines;
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_lines = ft_count_words(tab_s);
	tab_i = (int **)malloc(sizeof(int *) * nb_lines);
	while (i < nb_lines)
	{
		temp = ft_split(tab_s[i], ' ');
		tab_i[i] = malloc(sizeof(int) * ft_count_words(temp));
		j = 0;
		while (temp[j] != NULL)
		{
			tab_i[i][j] = ft_atoi(temp[j]);
			j++;
		}
		ft_free_tab_c(temp);
		i++;
	}
	return (tab_i);
}

int	**fill_col_tab(char **tab_s)
{
	int		**tab_col;
	char	**t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_col = (int **)malloc(sizeof(int *) * ft_count_words(tab_s));
	while (i < ft_count_words(tab_s))
	{
		t = ft_split(tab_s[i], ' ');
		tab_col[i] = malloc(sizeof(int) * ft_count_words(t));
		j = 0;
		while (t[j] != NULL)
		{
			tab_col[i][j] = ext_col(t[j]);
			j++;
		}
		ft_free_tab_c(t);
		i++;
	}
	return (tab_col);
}

t_map	*get_map(char *path)
{
	t_map	*map;
	char	**temp;
	char	**temp2;

	temp = fill_char_tab(path);
	temp2 = ft_split(temp[0], ' ');
	map = malloc(sizeof(t_map));
	map->map = fill_int_tab(temp);
	map->col = fill_col_tab(temp);
	map->size_x = ft_count_words(temp2);
	map->size_y = get_len_file(path) - 1;
	ft_free_tab_c(temp);
	ft_free_tab_c(temp2);
	map->path = path;
	map->title = get_title(path);
	map->win_x = 3000;
	map->win_y = 2000;
	return (map);
}
