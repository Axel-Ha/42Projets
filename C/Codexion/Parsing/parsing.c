/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:44:59 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/14 18:50:27 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	parser(char *av[], t_parsing *config)
{
	int	i;
	int	number;

	i = 0;
	while (i < 7)
	{
		number = ft_check_atoi(av[i + 1]);
		if (number == -1)
			return (1);
		config->arguments[i] = number;
		i++;
	}
	if (strcmp(av[i + 1], "fifo") != 0 && strcmp(av[i + 1], "edf") != 0)
		return (1);
	config->scheduler = av[i + 1];
	return (0);
}
