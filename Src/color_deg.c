/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_deg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:02:30 by lmatkows          #+#    #+#             */
/*   Updated: 2025/01/08 15:34:32 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	ft_col(int col1, int col2, int delt, int i)
{
	t_col	col;

	if (col1 == col2)
	{
		(void) delt;
		(void) i;
		return (col1);
	}
	col.colh1 = ft_hex_itoa(col1, "0123456789abcdef");
	col.R01 = extract_red(col.colh1, "0123456789abcdef");
	col.G01 = extract_green(col.colh1, "0123456789abcdef");
	col.B01 = extract_blue(col.colh1, "0123456789abcdef");
	col.colh2 = ft_hex_itoa(col2, "0123456789abcdef");
	col.R02 = extract_red(col.colh2, "0123456789abcdef");
	col.G02 = extract_green(col.colh2, "0123456789abcdef");
	col.B02 = extract_blue(col.colh2, "0123456789abcdef");
	col.R = col.R01 + ((col.R02 - col.R01) / abs(delt)) * i;
	col.G = col.G01 + ((col.G02 - col.G01) / abs(delt)) * i;
	col.B = col.B01 + ((col.B02 - col.B01) / abs(delt)) * i;
	free(col.colh1);
	free(col.colh2);
	return (col.R * 65280 + col.G * 255 + col.B);
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

	blue = 16 * find_i(col[5], base) + find_i(col[5], base);
	return (blue);
}