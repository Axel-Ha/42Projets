/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:25:07 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:23:55 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	while (*str)
	{
		if (*str == (char)searchedChar)
			return ((char *)str);
		str++;
	}
	if ((char)searchedChar == '\0')
		return ((char *)str);
	return (NULL);
}

/*
int	main(void)
{
	printf("%s\n", ft_strchr("Je suis", 0));
	printf("%s\n", strchr("Je suis", 0));
	printf("%s\n", ft_strchr("Je suis", 'J'));
	printf("%s\n", strchr("Je suis", 'J'));
	return (0);
}
*/