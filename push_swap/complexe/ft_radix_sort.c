/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:40:32 by ctu               #+#    #+#             */
/*   Updated: 2026/05/26 14:00:16 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b,
	t_stats *stats, int size)
{
	int	bit;
	int	j;
	int	max_bits;

	bit = 0;
	max_bits = 0;
	while (((1 << max_bits)) < size)
		max_bits++;
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> bit) & 1)
				ft_ra(stack_a, stats);
			else
				ft_pb(stack_a, stack_b, stats);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b, stats);
		bit++;
	}
}
