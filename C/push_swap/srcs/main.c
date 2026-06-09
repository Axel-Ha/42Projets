/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctu <ctu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:14:17 by ctu               #+#    #+#             */
/*   Updated: 2026/06/09 15:13:26 by ctu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_start_args(char **av, int ac, int start)
{
	char	**args;

	if ((ac - start == 1))
		args = ft_split(av[start], ' ');
	else
		args = av + start;
	return (args);
}

int	ft_args_protection(char **av, int ac, int start, char **args)
{
	if (!ft_check_args(args) || (ac - start == 0))
	{
		if ((ac - start == 1))
			ft_freearr(args, ft_countword(av[start], ' '));
		return (0);
	}
	return (1);
}

t_stats	*ft_stats_protection(t_flags *flags, t_stack **stack_a)
{
	t_stats	*stats;

	stats = ft_init_stats(flags);
	if (!stats)
	{
		ft_free(stack_a, stats, flags);
		return (0);
	}
	stats->disorder_metric = ft_compute_disorder(stack_a);
	if (stats->disorder_metric == 0.0)
	{
		ft_free(stack_a, stats, flags);
		return (0);
	}
	return (stats);
}

int	ft_launch_algo(t_stack **stack_a, t_flags *flags)
{
	t_stats	*stats;

	ft_init_index((*stack_a), ft_list_size(*stack_a));
	stats = ft_stats_protection(flags, stack_a);
	if (!stats)
		return (0);
	ft_select_algo(stack_a, flags, stats);
	if (flags->bench)
		ft_print_bench(flags, stats);
	return (ft_free(stack_a, stats, flags));
}

int	main(int ac, char **av)
{
	int		start;
	char	**args;
	t_stack	*stack_a;
	t_flags	*flags;

	if (ac < 2)
		return (0);
	start = 1;
	flags = ft_init_flags();
	args = NULL;
	if (!ft_get_flags(av, &start, flags))
		return (ft_free(NULL, NULL, flags));
	args = ft_start_args(av, ac, start);
	if (!ft_args_protection(av, ac, start, args))
		return (ft_free(NULL, NULL, flags));
	stack_a = ft_init_stack(args);
	if (ac - start == 1)
		ft_freearr(args, ft_countword(av[start], ' '));
	return (ft_launch_algo(&stack_a, flags));
}
