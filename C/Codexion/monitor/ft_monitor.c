/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:30:52 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/11 17:01:17 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_wake_up_all(t_simulation *monitor)
{
	int		i;

	i = 0;
	while (i < monitor->config->number_of_coders)
	{
		pthread_mutex_lock(&monitor->array_dongles[i]->mutex_dongle);
		pthread_cond_broadcast(&monitor->array_dongles[i]->cond_dongle);
		pthread_mutex_unlock(&monitor->array_dongles[i]->mutex_dongle);
		i++;
	}
}
