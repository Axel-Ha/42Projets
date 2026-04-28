/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:21:49 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:21:50 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
char	to_upper(unsigned int i, char c)
{
	i++;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
}

int	main(void)
{
	char	s1[] = "hello";
	char	*s2;

	s2 = ft_strmapi(s1, &to_upper);
	printf("%s\n", s2);
	return (0);
}
*/