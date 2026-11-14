/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:21:39 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/14 13:54:07 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	ft_solo_coder(t_coder *coder)
{
	coder->dongle_up->etat = TAKEN;
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_COMPILING);
	if (ft_sleep(coder->struct_simulation,
			coder->struct_simulation->config->time_to_burnout) == 1)
		ft_print_death_coder(coder->struct_simulation, coder->id_coder);
	return (0);
}

int	ft_compile(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_coder);
	coder->time_last_compile = ft_get_time_in_ms();
	pthread_mutex_unlock(&coder->mutex_coder);
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_COMPILING);
	if (ft_sleep(coder->struct_simulation,
			coder->struct_simulation->config->time_to_compile) == 1)
	{
		ft_release_dongle(coder, coder->dongle_up);
		ft_release_dongle(coder, coder->dongle_down);
		return (1);
	}
	return (0);
}

int	ft_debug(t_coder *coder)
{
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_DEBUGGING);
	if (ft_sleep(coder->struct_simulation,
			coder->struct_simulation->config->time_to_debug) == 1)
		return (1);
	return (0);
}

int	ft_refactor(t_coder *coder)
{
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_REFACTOR);
	if (ft_sleep(coder->struct_simulation,
			coder->struct_simulation->config->time_to_refactor) == 1)
		return (1);
	return (0);
}
