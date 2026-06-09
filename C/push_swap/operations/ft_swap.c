/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:44:46 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/27 13:34:33 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	ft_sa(t_stack **stack_a, t_stats *stats)
{
	ft_swap(*stack_a);
	stats->sa += 1;
	stats->total_ops += 1;
	ft_printf(1, "sa\n");
}

void	ft_sb(t_stack **stack_b, t_stats *stats)
{
	ft_swap(*stack_b);
	stats->sb += 1;
	stats->total_ops += 1;
	ft_printf(1, "sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	stats->rr += 1;
	stats->total_ops += 1;
	ft_printf(1, "ss\n");
}
