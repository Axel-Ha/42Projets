/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:55:38 by ctu               #+#    #+#             */
/*   Updated: 2026/05/27 11:30:41 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_index(t_stack *stack, int stack_size)
{
	t_stack	*tmp;
	t_stack	*max_node;

	while (--stack_size)
	{
		tmp = stack;
		max_node = NULL;
		while (tmp)
		{
			if (!tmp->index && (max_node == NULL || tmp->nbr > max_node->nbr))
				max_node = tmp;
			tmp = tmp->next;
		}
		if (max_node)
			max_node->index = stack_size;
	}
}
