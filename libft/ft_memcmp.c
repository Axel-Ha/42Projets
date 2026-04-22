/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:56:06 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 14:46:45 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
    size_t  i;

	s1 = ptr1;
	s2 = ptr2;
    i = 0;
	while (i < size)
	{
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_memcmp("array", "arzay9", 6));
	printf("%d\n", memcmp("array", "arzay9", 6));

	return (0);
}