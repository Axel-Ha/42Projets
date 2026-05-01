/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:10:35 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/01 18:53:52 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *source)
{
	size_t len;
	size_t i;
	char *res;

	i = 0;
	len = ft_strlen(source) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (source[i])
	{
		res[i] = source[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}