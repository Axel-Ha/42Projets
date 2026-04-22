/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:25:07 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/22 12:12:31 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	while (*str)
	{
		if (*str == searchedChar)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strchr("Je suis", 'a'));
	printf("%s\n", strchr("Je suis", 'a'));
	return (0);
}*/