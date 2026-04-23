/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:05:56 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/23 11:01:37 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest[dest_len] && (dest_len < size))
		dest_len++;
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	char	dest[20] = "12345";
	char	dest2[20] = "12345";
	char	src[] = "Worl";

	printf("%d\n", ft_strlcat(dest, src, 3));
	printf("%s\n", dest);
	printf("%d\n", strlcat(dest2, src, 10));
	printf("%s\n", dest2);
}
*/