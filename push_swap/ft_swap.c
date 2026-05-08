/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:44:46 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/08 13:16:16 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
	int tmp;

	if(!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->pos;
    stack->pos = stack->next->pos;
    stack->next->pos = tmp;
}

void ft_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_printf("sa\n");
}

void ft_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_printf("ss\n",);
}