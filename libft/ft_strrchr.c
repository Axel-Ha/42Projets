/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:42:51 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 12:20:35 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	size_t	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == searchedChar)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strrchr("Je suis", 'J'));
	printf("%s\n", strrchr("Je suis", 'J'));
	return (0);
}
*/