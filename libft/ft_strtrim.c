/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:21:58 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 12:23:14 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	if (end == 0)
		return (ft_substr(s1, 0, 0));
	end--;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

/*
int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "heaven++!e!h";
	set = "he!+";
	printf("avant: %s\n", s1);
	printf("apres: %s\n", ft_strtrim(s1, set));
	return (0);
}
*/