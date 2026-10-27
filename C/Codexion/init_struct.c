/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:05:25 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/27 18:17:07 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder	*init_struct_coder(t_parsing config)
{
	t_coder *coder;

	coder = malloc(sizeof(t_global));
	if (!coder)
		return (NULL);
	return (coder);
}