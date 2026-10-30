/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:29:53 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 20:47:31 by ahalifa          ###   ########.fr       */
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
				ft_free_queue_priority(&(dongles[i]->queue_priority));
				pthread_mutex_destroy(&dongles[i]->mutex_dongle);
				pthread_cond_destroy(&dongles[i]->cond_dongle);
				free(dongles[i]);
			}
			i++;
		}
		free(dongles);
	}
}

void	ft_free(t_parsing *config, t_simulation *monitor, int num)
{
	ft_free_dongles(monitor->array_dongles, num);
	ft_free_coders(monitor->array_coders, num);
	free(config);
	if (monitor)
	{
		pthread_mutex_destroy(&monitor->mutex_status);
		free(monitor);
	}
}

void	ft_free_queue_priority(t_queue **queue_priority)
{
	t_queue	*current;
	t_queue	*next;

	current = *queue_priority;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	queue_priority = NULL;
}
