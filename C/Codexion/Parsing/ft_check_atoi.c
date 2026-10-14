/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:31:40 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/14 12:32:02 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	ft_check_atoi(const char *str)
{
	int	result;

	result = 0;
	if (*str == ' ' || (*str >= 9 && *str <= 13))
		return (-1);
	if (*str == '+' || *str == '-')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (*str
					- '0') > INT_MAX % 10))
			return (-1);
		result = (*str - '0') + result * 10;
		str++;
	}
	if (*str != '\0')
		return (-1);
	else if (result == 0)
		return (-1);
	return (result);
}
