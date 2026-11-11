/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:25:12 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/05 11:53:50 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_set_simulation_ended(t_simulation *monitor)
{
	pthread_mutex_lock(&monitor->mutex_status);
	monitor->simulation_ended = 1;
	pthread_mutex_unlock(&monitor->mutex_status);
}

int	ft_get_is_simulation_finished(t_simulation *monitor)
{
	int	status;

	pthread_mutex_lock(&monitor->mutex_status);
	status = monitor->simulation_ended;
	pthread_mutex_unlock(&monitor->mutex_status);
	return (status);
}

static void	ft_put_log(t_simulation *monitor, int id_coder, const char *str)
{
	long long	now;

	now = ft_elapsed_time(monitor);
	printf("%lld %d %s\n", now, id_coder, str);
}

void	ft_print_death_coder(t_simulation *monitor, int id_coder)
{
	pthread_mutex_lock(&monitor->mutex_status);
	if (monitor->simulation_ended != 1)
	{
		monitor->simulation_ended = 1;
		ft_put_log(monitor, id_coder, "burned out");
	}
	pthread_mutex_unlock(&monitor->mutex_status);
}

void	ft_print_logs(t_simulation *monitor, int id_coder,
		t_log_coder log_coder)
{
	static const char	*message[] = {
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
	ft_put_log(monitor, id_coder, message[log_coder]);
	pthread_mutex_unlock(&monitor->mutex_status);
}
