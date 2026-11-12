/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:42:55 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/12 19:36:09 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

static void	*ft_coder_routine(void *arg)
{
	t_simulation	*monitor;
	t_coder			*coder;

	coder = (t_coder *)arg;
	monitor = coder->struct_simulation;
	if (monitor->config->number_of_coders == 1)
	{
		ft_solo_coder(coder);
		return (NULL);
	}
	while (ft_get_is_simulation_finished(monitor) != 1)
	{
		if (ft_coder_take_dongles(coder) == 1)
			return (NULL);
		if (ft_compile(coder) == 1)
			return (NULL);
		ft_release_dongles(coder);
		pthread_mutex_lock(&coder->mutex_coder);
		coder->count_compilation++;
		pthread_mutex_unlock(&coder->mutex_coder);
		if (ft_debug(coder) == 1 || ft_refactor(coder))
			return (NULL);
		//if (ft_refactor(coder) == 1)
		//	return (NULL);
	}
	return (NULL);
}

static void	*ft_monitor_routine(void *arg)
{
	t_simulation	*monitor;
	int				count;
	int				i;
	long long		last_compile;

	monitor = (t_simulation *)arg;
	while (ft_get_is_simulation_finished(monitor) != 1)
	{
		count = 0;
		i = 0;
		while (i < monitor->config->number_of_coders)
		{
			pthread_mutex_lock(&monitor->array_coders[i]->mutex_coder);
			last_compile = ft_get_time_in_ms()
				- monitor->array_coders[i]->time_last_compile;
			if (last_compile > monitor->config->time_to_burnout)
			{
				ft_print_death_coder(monitor,
					monitor->array_coders[i]->id_coder);
				ft_wake_up_all(monitor);
				pthread_mutex_unlock(&monitor->array_coders[i]->mutex_coder);
				return (NULL);
			}
			if (monitor->array_coders[i]->count_compilation >= monitor->config->number_of_compiles_required)
				count++;
			pthread_mutex_unlock(&monitor->array_coders[i]->mutex_coder);
			i++;
		}
		if (count == monitor->config->number_of_coders)
		{
			ft_set_simulation_ended(monitor);
			ft_wake_up_all(monitor);
		}
		usleep(1000);
	}
	return (NULL);
}

int	ft_thread_create_coder(t_simulation *monitor)
{
	int	i;

	i = 0;
	ft_init_last_compile(monitor);
	while (i < monitor->config->number_of_coders)
	{
		if (pthread_create(&(monitor->array_coders[i]->id_thread_coder), NULL,
				&ft_coder_routine, monitor->array_coders[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_thread_create_monitor(t_simulation *monitor)
{
	if (pthread_create(&(monitor->thread_monitor), NULL, &ft_monitor_routine,
			monitor) != 0)
		return (1);
	return (0);
}
