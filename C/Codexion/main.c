/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:47:38 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/02 14:39:18 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_create_coders_and_dongles(t_parsing *config, t_simulation *monitor,
		t_dongle **dgls, t_coder **coders)
{
	int	i;
	int	num_coders;

	i = 0;
	num_coders = config->number_of_coders;
	while (i < num_coders)
	{
		dgls[i] = init_struct_dongle(i + 1);
		if (!dgls[i])
			return (1);
		i++;
	}
	coders[0] = init_struct_coder(monitor, dgls[num_coders - 1], dgls[0], 1);
	if (!coders[0])
		return (1);
	i = 1;
	while (i < num_coders)
	{
		coders[i] = init_struct_coder(monitor, dgls[i], dgls[i - 1], i + 1);
		if (!coders[i])
			return (1);
		i++;
	}
	return (0);
}

t_simulation	*ft_create_monitor(t_parsing *config)
{
	t_dongle		**dongles;
	t_coder			**coders;
	t_simulation	*monitor;

	monitor = init_struct_simulation(config);
	if (!monitor)
		return (NULL);
	coders = malloc(sizeof(t_coder *) * config->number_of_coders);
	if (!coders)
	{
		ft_free(config, monitor);
		return (NULL);
	}
	memset(coders, 0, sizeof(t_coder *) * config->number_of_coders);
	dongles = malloc(sizeof(t_dongle *) * config->number_of_coders);
	if (!dongles)
	{
		ft_free(config, monitor);
		return (NULL);
	}
	memset(dongles, 0, sizeof(t_dongle *) * config->number_of_coders);
	monitor->array_coders = coders;
	monitor->array_dongles = dongles;
	return (monitor);
}

t_simulation	*ft_check_errors_init(t_parsing *config)
{
	t_simulation	*monitor;

	monitor = ft_create_monitor(config);
	if (!monitor)
		return (NULL);
	if (ft_create_coders_and_dongles(config, monitor, monitor->array_dongles,
			monitor->array_coders) == 1)
	{
		ft_free(config, monitor);
		return (NULL);
	}
	return (monitor);
}

t_simulation	*ft_parse_and_init(char *av[])
{
	t_parsing		*config;
	t_simulation	*monitor;

	// Faire un cas si num coder est a 1.
	monitor = NULL;
	config = malloc(sizeof(t_parsing));
	if (!config)
		return (NULL);
	if (parser(av, config) == 1)
	{
		ft_free(config, monitor);
		return (NULL);
	}
	valid_arguments(av, config);
	monitor = ft_check_errors_init(config);
	if (!monitor)
	{
		ft_free(config, monitor);
		return (NULL);
	}
	return (monitor);
}

int	main(int ac, char *av[])
{
	t_simulation	*monitor;

	if (ac == 9)
	{
		monitor = ft_parse_and_init(av);
		if (!monitor)
			return (1);
	}
	else
		return (1);
	ft_free(monitor->config, monitor);
	return (0);
}
// int	i;
// i = 0;
// while (i < monitor->config->number_of_coders)
//{
//	printf("coder id %d\n", monitor->array_coders[i]->id_coder);
//	printf("dongle up %d\n",
//		monitor->array_coders[i]->dongle_up->id_dongle);
//	printf("dongle down %d\n",
//		monitor->array_coders[i]->dongle_down->id_dongle);
//	i++;
//}