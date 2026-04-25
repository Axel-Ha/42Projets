/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:42:51 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/23 14:46:46 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)searchedChar)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}


int	main(void)
{
	printf("%s\n", ft_strrchr("Je suis", 'J' + 256));
	printf("%s\n", strrchr("Je suuis", 'J' + 256));
	return (0);
}
