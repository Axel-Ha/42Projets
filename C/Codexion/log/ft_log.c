/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:25:12 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/04 18:48:51 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_print_death_coder(t_simulation *monitor, int id_coder)
{
	long long	now;

	pthread_mutex_lock(&monitor->mutex_status);
	monitor->simulation_ended = 1;
	now = ft_elapsed_time(monitor);
	printf("%lld %d burned out\n", now, id_coder);
	pthread_mutex_unlock(&monitor->mutex_status);
}

void	ft_print_logs(t_simulation *monitor, int id_coder,
		t_log_coder log_coder)
{
	long long now;
	static const char *message[] = {
		[LOG_TAKING] = "has taken a dongle",
		[LOG_COMPILING] = "is compiling",
		[LOG_DEBUGGING] = "is debugging",
		[LOG_REFACTOR] = "is refactoring",
	};
	pthread_mutex_lock(&monitor->mutex_status);
	if (monitor->simulation_ended == 1)
	{
		pthread_mutex_unlock(&monitor->mutex_status);
		return ;
	}
	now = ft_elapsed_time(monitor);
	printf("%lld %d %s\n", now, id_coder, message[log_coder]);
	pthread_mutex_unlock(&monitor->mutex_status);
}