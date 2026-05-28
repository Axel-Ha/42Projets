/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:21:13 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:23:50 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
void	to_upper(unsigned int i, char *c)
{
	i++;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char	s1[] = "hello";

	ft_striteri(s1, &to_upper);
	printf("%s\n", s1);
	return (0);
}
*/
