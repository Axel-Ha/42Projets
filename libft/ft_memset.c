/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:03:36 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 11:14:46 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	unsigned char	*c;

	c = p;
	while (count--)
	{
		*c = value;
		c++;
	}
	return (p);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";

	printf("Before memset(): %s\n", str);
	// Fill 8 characters starting from str[13] with '.'
	ft_memset(str + 13, '.', 8 * sizeof(char));
	printf("After memset():  %s\n", str);
	return (0);
}
*/