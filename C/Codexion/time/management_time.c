/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:40:56 by ahalifa           #+#    #+#             */
/*   Updated: 2026/11/03 10:57:55 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

long long	ft_get_time_in_ms(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((ts.tv_sec * 1000LL) + (ts.tv_nsec / 10000000LL));
}
