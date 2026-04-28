/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:19:45 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:27:57 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = count * size;
	if (count == 0 || size == 0)
		return (malloc(0));
	if ((total_size) / size != size)
		return (NULL);
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total_size);
	return (result);
}
