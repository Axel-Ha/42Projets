/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:35:38 by ctu               #+#    #+#             */
/*   Updated: 2026/06/10 13:22:48 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_sort(t_stack **stack_a, t_stats *stats)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
	{
		ft_ra(stack_a, stats);
		ft_sa(stack_a, stats);
	}
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr
		&& (*stack_a)->nbr < (*stack_a)->next->next->nbr)
	{
		ft_sa(stack_a, stats);
		ft_ra(stack_a, stats);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr
		&& (*stack_a)->nbr < (*stack_a)->next->next->nbr)
		ft_sa(stack_a, stats);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		ft_rra(stack_a, stats);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr)
		ft_sa(stack_a, stats);
}

void	ft_simple_two(t_stack **stack_a, t_stats *stats)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		ft_sa(stack_a, stats);
}
