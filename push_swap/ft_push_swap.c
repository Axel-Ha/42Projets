/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:50:45 by ctu               #+#    #+#             */
/*   Updated: 2026/05/26 13:51:34 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_algo(t_stack **stack_a, t_flags *flags, t_stats *stats)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!flags)
		return ;
	if (flags->algo == 1)
		ft_select_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
	else if (flags->algo == 2)
		ft_chunk_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
	else if (flags->algo == 3)
		ft_radix_sort(stack_a, &stack_b, stats, ft_list_size(*stack_a));
	else
	{
		if (stats->disorder_metric < 0.2)
			ft_select_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
		else if (stats->disorder_metric >= 0.2 && stats->disorder_metric < 0.5)
			ft_chunk_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
		else
			ft_radix_sort(stack_a, &stack_b, stats, ft_list_size(*stack_a));
	}
}

void	ft_print_bench(t_flags *flags, t_stats *stats)
{
	ft_printf(1, "[bench] disorder: %f%%\n", stats->disorder_metric * 100);
	if (flags->algo == 1)
		ft_printf(1, "[bench] strategy: Simple / O(n2)\n");
	else if (flags->algo == 2)
		ft_printf(1, "[bench] strategy: Medium / O(n√n)\n");
	else if (flags->algo == 3)
		ft_printf(1, "[bench] strategy: Complex / O(n log n)\n");
	else
	{
		if (stats->disorder_metric < 0.2)
			ft_printf(1, "[bench] strategy: Adaptive / O(n2)\n");
		else if (stats->disorder_metric >= 0.2 && stats->disorder_metric < 0.5)
			ft_printf(1, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(1, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	ft_printf(1, "[bench] total_ops: %d\n", stats->total_ops);
	ft_printf(1, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", stats->sa,
		stats->sb, stats->ss, stats->pa, stats->pb);
	ft_printf(1, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		stats->ra, stats->rb, stats->rr, stats->rra, stats->rrb, stats->rrr);
}
