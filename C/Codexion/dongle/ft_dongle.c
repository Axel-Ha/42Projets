/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dongle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:32:24 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/12 19:29:39 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static void	ft_release_dongle(t_coder *coder, t_dongle *dongle)
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

void	ft_release_dongles(t_coder *coder)
{
	ft_release_dongle(coder, coder->dongle_up);
	ft_release_dongle(coder, coder->dongle_down);
}

int	ft_take_dongle(t_coder *coder, t_dongle *dongle)
{
	t_simulation	*monitor;
	struct timespec	ts;

	monitor = coder->struct_simulation;
	pthread_mutex_lock(&dongle->mutex_dongle);
	while (dongle->etat == TAKEN
		|| dongle->time_before_ready > ft_get_time_in_ms())
	{
		if (ft_get_is_simulation_finished(monitor) == 1)
		{
			pthread_mutex_unlock(&dongle->mutex_dongle);
			return (1);
		}
		ft_ms_to_timespec(dongle->time_before_ready, &ts);
		if (dongle->etat == TAKEN)
			pthread_cond_wait(&dongle->cond_dongle, &dongle->mutex_dongle);
		else
			pthread_cond_timedwait(&dongle->cond_dongle, &dongle->mutex_dongle,
				&ts);
	}
	dongle->etat = TAKEN;
	ft_print_logs(monitor, coder->id_coder, LOG_TAKING);
	pthread_mutex_unlock(&dongle->mutex_dongle);
	return (0);
}
