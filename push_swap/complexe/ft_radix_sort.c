/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:40:32 by ctu               #+#    #+#             */
/*   Updated: 2026/05/21 18:07:43 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	find_max_digits(t_stack *stack_a)
// {
// 	int max_val;
// 	int digits_nbr;

// 	digits_nbr = 0;
// 	max_val = stack_a->nbr;
// 	while (stack_a)
// 	{
// 		if (max_val < stack_a->nbr)
// 			max_val = stack_a->nbr;
// 		stack_a = stack_a->next;
// 	}
// 	while (max_val > 0)
// 	{
// 		max_val = max_val / 10;
// 		digits_nbr++;
// 	}
// 	return (digits_nbr);
// }

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, t_stats *stats, int size)
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