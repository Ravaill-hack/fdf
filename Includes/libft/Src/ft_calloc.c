/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:27:39 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/13 10:47:59 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

//	The calloc() function allocates memory for an array of  nmemb  elements
//	of  size bytes each and returns a pointer to the allocated memory.  The
//	memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
//  either  NULL,  or a unique pointer value that can later be successfully
//  passed to free().  If the multiplication of nmemb and size would result
//  in  integer  overflow, then calloc() returns an error.  By contrast, an
//  integer overflow would not be detected in the following  call  to  mal‐
//  loc(),  with the result that an incorrectly sized block of memory would
//  be allocated:

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if ((nmemb == 0) || (size == 0))
	{
		nmemb = 0;
		size = 0;
	}
	tab = malloc(nmemb * size);
	if (tab == 0)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

/*
#include <stdio.h>

int main(void)
{
	size_t nmemb = 8;
	size_t size = sizeof(int);
	int *tab = ft_calloc(nmemb, size);
	size_t i;

	i = 0;
	if (tab == NULL)
	{
		printf("Allocation non reussie\n");
		return (1);
	}
	while (i < nmemb)
	{
		printf("%d ", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/