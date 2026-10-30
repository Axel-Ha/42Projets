/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:47:38 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 20:44:36 by ahalifa          ###   ########.fr       */
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
			ft_free(config, NULL, 0);
			return (1);
		}

		valid_arguments(av, config);
		num_coders = config->number_of_coders;
		// Faire un cas si num coder est a 1.
		monitor = init_struct_simulation(config);
		if (!monitor)
		{
			ft_free(config, NULL, 0);
			return (1);
		}

		// MALLOC DE CODERS ET DONGLES
		coders = malloc(sizeof(t_coder *) * num_coders);
		dongles = malloc(sizeof(t_dongle *) * num_coders);
		if (!coders || !dongles)
		{
			ft_free(config, monitor, num_coders);
			return (1);
		}
		memset(coders, 0, sizeof(t_coder *) * num_coders);
		memset(dongles, 0, sizeof(t_dongle *) * num_coders);
		
		monitor->array_coders = coders;
		monitor->array_dongles = dongles;
		
		i = 0;
		// INIT DONGLES INIT DONGLES INIT DONGLES
		while (i < num_coders)
		{
			dongles[i] = init_struct_dongle(i);
			if (!dongles[i])
			{
				ft_free(config, monitor, num_coders);
				return (1);
			}
			i++;
		}
		//// INIT CODER INIT CODER INIT CODER
		coders[0] = init_struct_coder(monitor, dongles[num_coders - 1],
				dongles[0], 1);
		if (!coders[0])
		{
			ft_free(config, monitor, num_coders);
			return (1);
		}

		i = 1;
		while (i < num_coders)
		{
			//coders[i] = init_struct_coder(monitor, dongles[i], dongles[i - 1],
			//	i + 1);
			coders[i] = (i == 4) ? NULL : init_struct_coder(monitor, dongles[i], dongles[i - 1], i+1);

			if (!coders[i])
			{
				ft_free(config, monitor, num_coders);
				return (1);
			}
			i++;
		}
		i = 0;
		while(i < num_coders)
		{
			
			printf("id coder %d\n", coders[i]->id_coder);
			i++;
		}

	}
	else
	{
		fprintf(stderr, "Some arguments are missing\n");
		return (1);
	}
	ft_free(config, monitor, num_coders);
	return (0);
}