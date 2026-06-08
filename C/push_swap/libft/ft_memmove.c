/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:24:14 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 15:15:18 by ahalifa          ###   ########.fr       */
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
int	main(void)
{
	char	dest[20] = "ABCDEF";
	char	dest2[20] = "ABCDEF";

	puts("dest avant ft_memmove ");
	puts(dest);
	ft_memmove(dest, dest+1, 2);
	puts("\ndest apres ft_memmove ");
	puts(dest);
	memmove(dest2, dest2+1, 2);
	puts("\ndest2 apres memmove ");
	puts(dest2);
	return (0);
}
*/