/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:04:01 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/25 10:55:46 by ctu              ###   ########.fr       */
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
	if (!stats->bench)
		ft_printf(1, "ra\n");
	stats->ra += 1;
	stats->total_ops += 1;
}

void	ft_rb(t_stack **stack_b, t_stats *stats)
{
	ft_rotate(stack_b);
	if (!stats->bench)
		ft_printf(1, "rb\n");
	stats->rb += 1;
	stats->total_ops += 1;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	stats->rr += 1;
	stats->total_ops += 1;
	if (!stats->bench)
		ft_printf(1, "rr\n");
}
