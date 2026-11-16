/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dongle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:32:24 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/16 16:12:25 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_release_dongle(t_coder *coder, t_dongle *dongle)
{
	t_simulation	*monitor;

	monitor = coder->struct_simulation;
	pthread_mutex_lock(&dongle->mutex_dongle);
	dongle->time_before_ready = ft_get_time_in_ms()
		+ monitor->config->dongle_cooldown;
	dongle->etat = FREE;
	pthread_cond_broadcast(&dongle->cond_dongle);
	pthread_mutex_unlock(&dongle->mutex_dongle);
}

static void	ft_wait_dongle(t_dongle *blocking)
{
	struct timespec	ts;

	if (blocking->time_before_ready > ft_get_time_in_ms())
	{
		ft_ms_to_timespec(blocking->time_before_ready, &ts);
		pthread_cond_timedwait(&blocking->cond_dongle, &blocking->mutex_dongle,
			&ts);
	}
	else
		pthread_cond_wait(&blocking->cond_dongle, &blocking->mutex_dongle);
}

long long	ft_get_key(t_coder *coder)
{
	long long	key;
	t_parsing	*config;

	config = coder->struct_simulation->config;
	if (config->scheduler == FIFO)
		key = ft_take_ticket(coder->struct_simulation);
	else
	{
		pthread_mutex_lock(&(coder->mutex_coder));
		key = coder->time_last_compile + config->time_to_burnout;
		pthread_mutex_unlock(&(coder->mutex_coder));
	}
	return (key);
}

static void	ft_wait_blocking_dongle(t_coder *coder)
{
	t_dongle	*blocking;

	if (ft_can_take_dongle(coder->dongle_up, coder->id_coder) == 0)
	{
		blocking = coder->dongle_up;
		pthread_mutex_unlock(&coder->dongle_down->mutex_dongle);
	}
	else
	{
		blocking = coder->dongle_down;
		pthread_mutex_unlock(&coder->dongle_up->mutex_dongle);
	}
	ft_wait_dongle(blocking);
	pthread_mutex_unlock(&blocking->mutex_dongle);
	ft_lock_both_dongle(coder);
}

int	ft_take_dongles(t_coder *coder)
{
	long long	key;

	key = ft_get_key(coder);
	ft_lock_both_dongle(coder);
	ft_heap_push(&coder->dongle_up->queue_priority, coder->id_coder, key);
	ft_heap_push(&coder->dongle_down->queue_priority, coder->id_coder, key);
	while (1)
	{
		if (ft_get_is_simulation_finished(coder->struct_simulation) == 1)
		{
			ft_heap_remove(&coder->dongle_up->queue_priority, coder->id_coder);
			ft_heap_remove(&coder->dongle_down->queue_priority,
				coder->id_coder);
			return (ft_unlock_both_dongle(coder));
		}
		if (ft_can_take_dongle(coder->dongle_up, coder->id_coder) == 1
			&& ft_can_take_dongle(coder->dongle_down, coder->id_coder) == 1)
			break ;
		ft_wait_blocking_dongle(coder);
	}
	ft_heap_remove(&coder->dongle_up->queue_priority, coder->id_coder);
	ft_heap_remove(&coder->dongle_down->queue_priority, coder->id_coder);
	ft_state_print_and_unlock(coder);
	return (0);
}
