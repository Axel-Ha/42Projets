/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:36:36 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:24:36 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	const unsigned char	*ptrsrc;
	unsigned char		*ptrdest;

	ptrsrc = src;
	ptrdest = dest;
	while (size--)
	{
		*ptrdest = *ptrsrc;
		ptrdest++;
		ptrsrc++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	a;
	int	b;

	// Initialize a variable
	a = 20;
	b = 10;
	printf("b avant: %d\n", b);
	// Use memcpy to copy the value of 'a' into 'b'
	ft_memcpy(&b, &a, sizeof(int));
	printf("b apres: %d\n", b);
	return (0);
}
*/