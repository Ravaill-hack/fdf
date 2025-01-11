/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:02:30 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/11 15:35:32 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ft_col(int col1, int col2, int delt, int i)
{
	t_col	col;

	if (col1 == col2 || delt == 0)
	{
		(void) delt;
		(void) i;
		return (col1);
	}
	col.colh1 = ft_hex_itoa(col1, "0123456789abcdef");
	col.r01 = extract_red(col.colh1, "0123456789abcdef");
	col.g01 = extract_green(col.colh1, "0123456789abcdef");
	col.b01 = extract_blue(col.colh1, "0123456789abcdef");
	col.colh2 = ft_hex_itoa(col2, "0123456789abcdef");
	col.r02 = extract_red(col.colh2, "0123456789abcdef");
	col.g02 = extract_green(col.colh2, "0123456789abcdef");
	col.b02 = extract_blue(col.colh2, "0123456789abcdef");
	col.r = col.r01 + (float)(((col.r02 - col.r01) / abs(delt)) * i);
	col.g = col.g01 + (float)(((col.g02 - col.g01) / abs(delt)) * i);
	col.b = col.b01 + (float)(((col.b02 - col.b01) / abs(delt)) * i);
	free(col.colh1);
	free(col.colh2);
	return ((int)(col.r) << 16 | (int)(col.g) << 8 | (int)(col.b));
}

int	extract_red(char *col, char *base)
{
	int	red;

	red = 16 * find_i(col[0], base) + find_i(col[1], base);
	return (red);
}

int	extract_green(char *col, char *base)
{
	int	green;

	green = 16 * find_i(col[2], base) + find_i(col[3], base);
	return (green);
}

int	extract_blue(char *col, char *base)
{
	int	blue;

	blue = 16 * find_i(col[4], base) + find_i(col[5], base);
	return (blue);
}
