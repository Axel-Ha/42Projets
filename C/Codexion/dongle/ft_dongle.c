/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dongle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:32:24 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/13 10:18:05 by ahalifa          ###   ########.fr       */
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

	if (blocking->etat == TAKEN)
		pthread_cond_wait(&blocking->cond_dongle, &blocking->mutex_dongle);
	else
	{
		ft_ms_to_timespec(blocking->time_before_ready, &ts);
		pthread_cond_timedwait(&blocking->cond_dongle, &blocking->mutex_dongle,
			&ts);
	}
}
static int	ft_is_available(t_dongle *dongle)
{
	if (dongle->etat == TAKEN)
		return (0);
	if (dongle->time_before_ready > ft_get_time_in_ms())
		return (0);
	return (1);
}

int	ft_take_dongles(t_coder *coder)
{
	t_dongle	*blocking;

	while (1)
	{
		pthread_mutex_lock(&coder->dongle_up->mutex_dongle);
		pthread_mutex_lock(&coder->dongle_down->mutex_dongle);
		if (ft_get_is_simulation_finished(coder->struct_simulation) == 1)
		{
			pthread_mutex_unlock(&coder->dongle_up->mutex_dongle);
			pthread_mutex_unlock(&coder->dongle_down->mutex_dongle);
			return (1);
		}
		if (ft_is_available(coder->dongle_up)
			&& ft_is_available(coder->dongle_down))
			break ;
		if (!ft_is_available(coder->dongle_up))
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
	}
	coder->dongle_up->etat = TAKEN;
	coder->dongle_down->etat = TAKEN;
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_TAKING);
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_TAKING);
	pthread_mutex_unlock(&coder->dongle_up->mutex_dongle);
	pthread_mutex_unlock(&coder->dongle_down->mutex_dongle);
	return (0);
}
