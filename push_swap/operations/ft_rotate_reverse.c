/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:34:16 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/25 10:54:52 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*beforelast;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	beforelast = *stack;
	while (beforelast->next->next != NULL)
		beforelast = beforelast->next;
	last = beforelast->next;
	last->next = *stack;
	beforelast->next = NULL;
	*stack = last;
}

void	ft_rra(t_stack **stack_a, t_stats *stats)
{
	ft_rotate_reverse(stack_a);
	stats->rra += 1;
	stats->total_ops += 1;
	if (!stats->bench)
		ft_printf(1, "rra\n");
}

void	ft_rrb(t_stack **stack_b, t_stats *stats)
{
	ft_rotate_reverse(stack_b);
	stats->rrb += 1;
	stats->total_ops += 1;
	if (!stats->bench)
		ft_printf(1, "rrb\n");
}
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
	stats->rrr += 1;
	stats->total_ops += 1;
	if (!stats->bench)
		ft_printf(1, "rrr\n");
}