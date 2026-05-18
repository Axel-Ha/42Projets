/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:12:40 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/18 11:56:23 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	stats->pa += 1;
	stats->total_ops += 1;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	stats->pb += 1;
	stats->total_ops += 1;
	write(1, "pb\n", 3);
}