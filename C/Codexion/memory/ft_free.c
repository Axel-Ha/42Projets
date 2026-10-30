/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:29:53 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 15:55:10 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void ft_free_coders(t_coder **coders, int num)
{
	int i;

	i = 0;
	if (coders)
	{
		while(i < num)
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

void ft_free_dongles(t_dongle **dongles, int num)
{
	int i;

	i = 0;
	if (dongles)
	{
		while(i < num)
		{
			if (dongles[i])
			{
				pthread_mutex_destroy(&dongles[i]->mutex_dongle);
				free(dongles[i]);
			}
			i++;
		}
		free(dongles);
	}
}
int	ft_free(t_parsing *config, t_coder **coders, t_dongle **dongles, t_simulation *monitor,
int num)
{
	ft_free_dongles(dongles, num);
	ft_free_coders(coders, num);
	free(config);
	if(monitor)
	{
		pthread_mutex_destroy(&monitor->mutex_status);
		free(monitor);
	}
	return (0);
}