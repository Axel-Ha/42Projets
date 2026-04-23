/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:15:23 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/23 13:05:36 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	while ((*first && (*first == *second) && n > 0))
	{
		first++;
		second++;
		n--;
	}
	return (*first - *second);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("Jea suis", "Jea suia", 3));
	printf("%d\n", strncmp("Jea suis", "Jex suib", 3));
	return (0);
}
*/
