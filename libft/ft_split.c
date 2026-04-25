/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:03:07 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/24 10:17:52 by ahalifa          ###   ########.fr       */
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
	char	*newString;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	newString = malloc(sizeof(char) * (i + 1));
	if(!newString)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		newString[i] = s[i];
		i++;
	}
	newString[i] = '\0';
	return (newString);
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
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	newarr[i] = NULL;
	return (newarr);
}

int	main(void)
{
	char **arr;

	char *phrase = "  tripouille  42  ";
	arr = ft_split(phrase, ' ');
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
