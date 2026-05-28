/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:03:07 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/21 19:59:26 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*ft_word(char const *s, char c)
{
	char	*newstring;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	newstring = malloc(sizeof(char) * (i + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		newstring[i] = s[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

void	*ft_freearr(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**newarr;
	int		i;

	newarr = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!newarr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			newarr[i] = ft_word(s, c);
			if (!newarr[i])
				return (ft_freearr(newarr, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	newarr[i] = NULL;
	return (newarr);
}

/*
int	main(void)
{
	char	**arr;
	char	*phrase;
	int		i;

	phrase = "  tripouille  42  ";
	arr = ft_split(phrase, ' ');
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
*/
