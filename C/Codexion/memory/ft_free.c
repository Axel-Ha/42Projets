/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:29:53 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 15:40:23 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	ft_free(t_parsing *config, t_coder **coders, t_dongle **dongles, t_simulation *monitor,
int num)
{
	int i;
	
	i = 0;
	if (coders)
	{
		while(i < num)
		{
			if (coders[i])
				free(coders[i]);
			i++;
		}
		free(coders);
	}
	i = 0;
	if (dongles)
	{
		while(i < num)
		{
			if (dongles[i])
				free(dongles[i]);
			i++;
		}
		free(dongles);
	}
	free(config);
	free(monitor);
	return (0);
}