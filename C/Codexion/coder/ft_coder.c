/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:21:39 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/13 07:48:36 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	ft_solo_coder(t_coder *coder)
{
	(void)coder;
	return (0);
	// ft_take_dongle(coder, coder->dongle_up);
	// if(ft_take_dongle(coder, coder->dongle_down) == 1)
	//	printf("TESTESTEST");
	// return (0);
}

int	ft_coder_take_dongles(t_coder *coder)
{
	if (ft_take_dongle(coder, coder->dongle_up) == 1)
		return (1);
	if (ft_take_dongle(coder, coder->dongle_down) == 1)
		return (1);
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
		ft_release_dongles(coder);
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
