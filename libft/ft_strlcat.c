/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:05:56 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 17:40:09 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len <= size)
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


int	main(void)
{
	char	dest[12] = "un";
	char	dest2[12] = "un";
	char	src[] = "deux";

	printf("%d\n", strlcat(dest, src, 1));
	printf("%s\n", dest);
	printf("%d\n", strlcat(dest2, src, 1));
	printf("%s\n", dest2);
}
