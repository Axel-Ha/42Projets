/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:05:25 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/14 15:14:38 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

t_simulation	*init_struct_simulation(t_parsing *config)
{
	t_simulation	*simulation;

	simulation = malloc(sizeof(t_simulation));
	if (!simulation)
		return (NULL);
	simulation->simulation_ended = 0;
	simulation->config = config;
	simulation->array_coders = NULL;
	simulation->array_dongles = NULL;
	simulation->start_time_simulation = 0;
	if (pthread_mutex_init(&simulation->mutex_status, NULL))
	{
		free(simulation);
		return (NULL);
	}
	return (simulation);
}

t_coder	*init_struct_coder(t_simulation *simulation, t_dongle *dongle_up,
		t_dongle *dongle_down, int id)
{
	t_coder	*coder;

	coder = malloc(sizeof(t_coder));
	if (!coder)
		return (NULL);
	coder->id_coder = id;
	coder->etat = WAITING;
	coder->count_compilation = 0;
	coder->dongle_up = dongle_up;
	coder->dongle_down = dongle_down;
	coder->struct_simulation = simulation;
	coder->time_last_compile = 0;
	if (pthread_mutex_init(&coder->mutex_coder, NULL))
	{
		free(coder);
		return (NULL);
	}
	return (coder);
}

t_dongle	*init_struct_dongle(int id)
{
	t_dongle	*dongle;

	dongle = malloc(sizeof(t_dongle));
	if (!dongle)
		return (NULL);
	dongle->id_dongle = id;
	dongle->etat = FREE;
	dongle->time_before_ready = 0;
	dongle->queue_priority.size = 0;
	if (pthread_mutex_init(&dongle->mutex_dongle, NULL))
	{
		free(dongle);
		return (NULL);
	}
	if (pthread_cond_init(&dongle->cond_dongle, NULL))
	{
		pthread_mutex_destroy(&dongle->mutex_dongle);
		free(dongle);
		return (NULL);
	}
	return (dongle);
}


void	ft_init_last_compile(t_simulation *monitor)
{
	int		i;

	i = 0;
	while (i < monitor->config->number_of_coders)
	{
		monitor->array_coders[i]->time_last_compile = (
				monitor->start_time_simulation);
		i++;
	}
}
