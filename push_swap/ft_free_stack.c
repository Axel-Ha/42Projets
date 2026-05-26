/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:48:06 by ctu               #+#    #+#             */
/*   Updated: 2026/05/26 13:49:35 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_stacks(t_stack **stack_a, char **args, t_stats *stats,
	t_flags *flags)
{
	ft_stack_clear(stack_a);
	free(args);
	free(stats);
	free(flags);
	return (0);
}
