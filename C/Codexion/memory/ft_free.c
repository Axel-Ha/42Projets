/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:29:53 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/14 14:15:53 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_free_coders(t_coder **coders, int num)
{
	int	i;

	i = 0;
	if (coders)
	{
		while (i < num)
		{
			if (coders[i])
			{
				pthread_mutex_destroy(&coders[i]->mutex_coder);
				free(coders[i]);
			}
			i++;
		}
		free(coders);
	}
}

void	ft_free_dongles(t_dongle **dongles, int num)
{
	int	i;

	i = 0;
	if (dongles)
	{
		while (i < num)
		{
			if (dongles[i])
			{
				pthread_mutex_destroy(&dongles[i]->mutex_dongle);
				pthread_cond_destroy(&dongles[i]->cond_dongle);
				free(dongles[i]);
			}
			i++;
		}
		free(dongles);
	}
}

void	ft_free_simulation(t_simulation *monitor)
{
	int	num;

	if (!monitor)
		return ;
	num = 0;
	if (monitor->config)
	{
		num = monitor->config->number_of_coders;
		free(monitor->config);
	}
	ft_free_dongles(monitor->array_dongles, num);
	ft_free_coders(monitor->array_coders, num);
	pthread_mutex_destroy(&monitor->mutex_status);
	free(monitor);
}
