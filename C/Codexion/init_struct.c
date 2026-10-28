/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:05:25 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/28 19:21:51 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_simulation	*init_struct_simulation(t_parsing *config)
{
	t_simulation	*simulation;

	simulation = malloc(sizeof(t_simulation));
	if (!simulation)
		return (NULL);
	simulation->start_time_simulation.tv_sec = 0;
	simulation->status_simulation = 0;
	simulation->config = config;
	simulation->array_coders = NULL;
	simulation->array_dongles = NULL;
	if(pthread_mutex_init(&simulation->mutex_status, NULL))
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
	coder->etat = 0;
	coder->count_compilation = 0;
	coder->time_last_compile.tv_sec = 0;
	coder->dongle_up = dongle_up;
	coder->dongle_down = dongle_down;
	coder->struct_simulation = simulation;
	memset(&coder->time_last_compile, 0, sizeof(struct timespec));
	if(pthread_mutex_init(&coder->mutex_coder, NULL))
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
	dongle->etat = 0;
	dongle->queue_priority = NULL;
	memset(&dongle->time_before_ready, 0, sizeof(struct timespec));
	if(pthread_mutex_init(&dongle->mutex_dongle, NULL))
	{
		free(dongle);
		return (NULL);
	}
	if(pthread_cond_init(&dongle->cond_dongle, NULL))
	{
		pthread_mutex_destroy(&dongle->mutex_dongle);
		free(dongle);
		return (NULL);
	}
	return (dongle);
}

t_queue	*init_struct_queue_priority(int id_coder, long long key)
{
	t_queue *queue_prio;

	queue_prio = malloc(sizeof(t_queue));
	if (!queue_prio)
		return (NULL);
	queue_prio->id_coder = id_coder;
	queue_prio->key = key;
	queue_prio->next = NULL;
	return (queue_prio);
}