/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:48:06 by ctu               #+#    #+#             */
/*   Updated: 2026/05/27 11:08:41 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_stacks(t_stack **stack_a, t_stats *stats, t_flags *flags)
{
	ft_stack_clear(stack_a);
	free(stats);
	free(flags);
	return (0);
}
