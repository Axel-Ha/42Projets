/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:19:45 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/28 12:21:33 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	total_size = count * size;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total_size);
	return (result);
}

/*
int	main(void)
{
	printf("%d", ft_calloc(6,60));
	// printf("%d", calloc(6,60));
	return (0);
}
*/
