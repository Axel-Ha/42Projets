/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:15:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:23:22 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (first[i] && (first[i] == second[i]) && i < n - 1)
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("Jea suis", "", 0));
	printf("%d\n", strncmp("Jea suis", "", 0));
	return (0);
}
*/
