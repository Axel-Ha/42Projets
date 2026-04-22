/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:36:36 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 11:18:37 by ahalifa          ###   ########.fr       */
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
	// Initialize a variable
	int a = 20;
	int b = 10;
    
	printf("Value of b before calling memcpy: %d\n", b);
    
	// Use memcpy to copy the value of 'a' into 'b'
	ft_memcpy(&b, &a, sizeof(int));
    
	printf("Value of b after calling memcpy: %d\n", b);
    
	return (0);
}
*/