/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:40:56 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/13 07:50:10 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

long long	ft_get_time_in_ms(void)
{
	struct timespec	ts;

	if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
		return (-1);
	return ((long long)ts.tv_sec * 1000LL + (long long)ts.tv_nsec / 1000000LL);
}

long long	ft_elapsed_time(t_simulation *monitor)
{
	return (ft_get_time_in_ms() - monitor->start_time_simulation);
}

void	ft_ms_to_timespec(long long time_ms, struct timespec *ts)
{
	long long	sec;
	long long	remainder_ms;
	long long	remainder_ns;

	sec = time_ms / 1000;
	remainder_ms = time_ms % 1000;
	remainder_ns = remainder_ms * 1000000;
	ts->tv_nsec = remainder_ns;
	ts->tv_sec = sec;
}

int	ft_sleep(t_simulation *monitor, long long time)
{
	long long	end_time;

	end_time = ft_get_time_in_ms() + time;
	while (ft_get_time_in_ms() < end_time)
	{
		if (ft_get_is_simulation_finished(monitor))
			return (1);
		usleep(1000);
	}
	return (0);
}
