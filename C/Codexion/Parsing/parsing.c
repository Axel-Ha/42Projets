/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:44:59 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 12:03:40 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	parser(char *av[], t_parsing *config)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (ft_check_atoi(av[i + 1]) == -1)
			return (1);
		i++;
	}
	if (strcmp(av[i + 1], "fifo") != 0 && strcmp(av[i + 1], "edf") != 0)
		return (1);
	config->scheduler = av[i + 1];
	return (0);
}

void	valid_arguments(char *av[], t_parsing *config)
{
	config->number_of_coders = ft_check_atoi(av[1]);
	config->time_to_burnout = ft_check_atoi(av[2]);
	config->time_to_compile = ft_check_atoi(av[3]);
	config->time_to_debug = ft_check_atoi(av[4]);
	config->time_to_refactor = ft_check_atoi(av[5]);
	config->number_of_compiles_required = ft_check_atoi(av[6]);
	config->dongle_cooldown = ft_check_atoi(av[7]);
	config->scheduler = av[8];
}