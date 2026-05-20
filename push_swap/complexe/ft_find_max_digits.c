/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:40:32 by ctu               #+#    #+#             */
/*   Updated: 2026/05/20 16:34:01 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_digits(t_stack *stack_a)
{
	int max_val;
	int digits_nbr;

	digits_nbr = 0;
	max_val = stack_a->nbr;
	while (stack_a)
	{
		if (max_val < stack_a->nbr)
			max_val = stack_a->nbr;
		stack_a = stack_a->next;
	}
	while (max_val > 0)
	{
		max_val = max_val / 10;
		digits_nbr++;
	}
	return (digits_nbr);
}

