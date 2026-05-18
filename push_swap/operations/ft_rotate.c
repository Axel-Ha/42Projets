/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:04:01 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/18 11:56:36 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_listlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack **stack_a, t_stats *stats)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
	stats->ra += 1;
	stats->total_ops += 1;
}

void	ft_rb(t_stack **stack_b, t_stats *stats)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
	stats->rb += 1;
	stats->total_ops += 1;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	stats->rr += 1;
	stats->total_ops += 1;
	ft_printf("rr\n");
}
