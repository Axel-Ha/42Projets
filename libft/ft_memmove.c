/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:24:14 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 11:15:04 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (!to && !from)
		return (NULL);
	dest = to;
	src = from;
	if (dest < src)
	{
		while (size--)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	else if (dest > src)
	{
		while (size--)
			dest[size] = src[size];
	}
	return (to);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "testt";
	char	dest2[] = "testt";
	char	src[] = "Quiz";

	puts("dest avant ft_memmove ");
	puts(dest);
	ft_memmove(dest, src, 2);
	puts("\ndest apres ft_memmove ");
	puts(dest);
	memmove(dest2, src, 2);
	puts("\ndest2 apres memmove ");
	puts(dest2);
	return (0);
}
*/
