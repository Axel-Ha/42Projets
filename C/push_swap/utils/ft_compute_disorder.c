/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:47:43 by ctu               #+#    #+#             */
/*   Updated: 2026/05/26 13:47:46 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	ft_compute_disorder(t_stack **stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*j;
	t_stack	*i;

	mistakes = 0;
	total_pairs = 0;
	i = *stack_a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->nbr > j->nbr)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (mistakes == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}
