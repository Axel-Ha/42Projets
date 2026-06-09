/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:35:38 by ctu               #+#    #+#             */
/*   Updated: 2026/06/09 16:22:40 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_sort(t_stack **stack_a, t_stats *stats)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
	{
		ft_ra(stack_a, stats);
		ft_ra(stack_a, stats);
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
