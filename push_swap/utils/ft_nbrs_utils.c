/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:58:06 by ctu               #+#    #+#             */
/*   Updated: 2026/05/26 13:58:07 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_check_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (ft_issign(nbr[i]) && nbr[i + 1] != '\0')
		i++;
	if (!ft_isdigit(nbr[i]))
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_ranges(char *nbr)
{
	long	n;

	n = ft_atoi(nbr);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}
