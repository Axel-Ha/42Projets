/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:21:39 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/11 16:38:31 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	ft_solo_coder(t_coder *coder, t_dongle *dongle)
{
	(void)coder;
	(void)dongle;
	return (0);
}

int	ft_coder_take_dongles(t_coder *coder)
{
	if (ft_take_dongle(coder, coder->dongle_up) == 1)
		return (1);
	if (ft_take_dongle(coder, coder->dongle_down) == 1)
		return (1);
	return (0);
}
