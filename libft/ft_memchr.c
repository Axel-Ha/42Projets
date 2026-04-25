/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:26:55 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/23 12:12:02 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBlock, int searchedChar, size_t size)
{
	unsigned char	*buf;
	size_t	i;
	
	buf = (unsigned char *)memBlock;
	i = 0;
	while (i < size)
	{
		if (buf[i] == (unsigned char)searchedChar)
			return ((void *)buf + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("%s\n", ft_memchr("Je s7uis", '7', 3));
	printf("%s\n", memchr("Je s7uis", '7', 3));
	return (0);
}
*/

