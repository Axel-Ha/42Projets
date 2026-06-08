/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:21:10 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:30:21 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = ft_strlen(source) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (source[i])
	{
		res[i] = source[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
