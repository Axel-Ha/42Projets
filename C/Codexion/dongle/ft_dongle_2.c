/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dongle_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:20:49 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/13 11:10:24 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	ft_lock_both_dongle(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle_up->mutex_dongle);
	pthread_mutex_lock(&coder->dongle_down->mutex_dongle);
}
int	ft_unlock_both_dongle(t_coder *coder)
{
	pthread_mutex_unlock(&coder->dongle_up->mutex_dongle);
	pthread_mutex_unlock(&coder->dongle_down->mutex_dongle);
	return (1);
}
void	ft_unlock_print_and_state(t_coder *coder)
{
	coder->dongle_up->etat = TAKEN;
	coder->dongle_down->etat = TAKEN;
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_TAKING);
	ft_print_logs(coder->struct_simulation, coder->id_coder, LOG_TAKING);
	pthread_mutex_unlock(&coder->dongle_up->mutex_dongle);
	pthread_mutex_unlock(&coder->dongle_down->mutex_dongle);
}