/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:47:38 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 15:55:16 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int ac, char *av[])
{
	t_parsing *config;
	t_dongle **dongles;
	t_coder **coders;
	t_simulation *monitor;
	int num_coders;
	int i;
	
	if (ac == 9)
	{
		config = malloc(sizeof(t_parsing));
		if (!config)
			return (1);
		if (parser(av, config) == 1)
		{
			fprintf(stderr, "Something wrong with the arguments\n");
			return (ft_free(config, NULL, NULL, NULL, 0));
		}

		valid_arguments(av, config);
		num_coders = config->number_of_coders;
		monitor = init_struct_simulation(config);
		if (!monitor)
		{
			ft_free(config, NULL, NULL, NULL, 0);
			return (1);
		}

		//MALLOC DE CODERS ET DONGLES  
		coders = malloc(sizeof(t_coder *) * num_coders);
		dongles = malloc(sizeof(t_dongle *) * num_coders);
		if (!coders || !dongles)
			return (ft_free(config, coders, dongles, monitor, num_coders));
		i = 0;
		while(i < num_coders)
		{
			dongles[i] = NULL;
			coders[i] = NULL;
			i++;
		}
		

		i = 0;
		//INIT DONGLES INIT DONGLES INIT DONGLES 
		while (i < num_coders)
		{
			dongles[i] = init_struct_dongle(i);
			if (!dongles[i])
				return (ft_free(config, NULL, dongles, monitor, num_coders));

			i++;
		}
		//INIT CODER INIT CODER INIT CODER 
		coders[0] = init_struct_coder(monitor, dongles[num_coders - 1],
				dongles[0], 0);
		if (!coders[0])
			return (ft_free(config, coders, dongles, monitor, num_coders));
		i = 1;
		while (i < num_coders)
		{
			coders[i] = init_struct_coder(monitor, dongles[i], dongles[i - 1],
					i);
			if (!coders[i])
				return (ft_free(config, coders, dongles, monitor, num_coders));
			i++;
		}
		monitor->array_coders = coders;
		monitor->array_dongles = dongles;
	}
	else
	{
		fprintf(stderr, "Some arguments are missing\n");
		return (1);
	}

	return (ft_free(config, coders, dongles, monitor, num_coders));
}