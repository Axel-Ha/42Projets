/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:13 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:35:12 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(char *s, int n, int *pos)
{
	if (n > 9)
	{
		ft_putnbr(s, n / 10, pos);
		ft_putnbr(s, n % 10, pos);
	}
	else
	{
		s[*pos] = n + '0';
		(*pos)++;
	}
}

int	ft_getlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*newstring;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	newstring = malloc(ft_getlen(n) + 1);
	if (!newstring)
		return (NULL);
	if (n < 0)
	{
		newstring[i] = '-';
		i++;
		n *= -1;
	}
	ft_putnbr(newstring, n, &i);
	newstring[i] = '\0';
	return (newstring);
}

/*
{
	printf("%s", ft_itoa(-123));
	return (0);
}
*/
