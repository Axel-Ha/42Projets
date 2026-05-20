#include "../printf/ft_printf.h"
#include "push_swap.h"

void	ft_select_algo(t_stack **stack_a, t_flags *flags, t_stats *stats)
{
	t_stack	*stack_b;

	// t_stats stats;
	stack_b = NULL;
	if (!flags)
		return ;
	if (flags->algo == 1)
		ft_select_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
	// else if (flags.algo == 2)
	// ft_chunk_sort();
	// ft_printf("test");
	// else if (flags.algo == 3)
	// ft_radix_sort();
	else
	{
		if (stats->disorder_metric < 0.2)
			ft_select_sort(stack_a, &stack_b, ft_list_size(*stack_a), stats);
		// 	// else if(disorder_metric >= 0.2 && disorder_metric < 0.5)
		// 	// 	// ft_chunk_sort();
		// 	// else
		// 	// 	ft_radix_sort();
	}
}

void	ft_print_bench(t_flags *flags, t_stats *stats)
{
	printf("[bench] disorder: %.2f%%\n", stats->disorder_metric * 100);
	ft_printf("[bench] disorder: %f%%\n", stats->disorder_metric * 100);
	if (flags->algo == 1)
		ft_printf("[bench] strategy: Simple / O(n2)\n");
	else if (flags->algo == 2)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (flags->algo == 3)
		printf("[bench] strategy: Complex / O(n log n)\n");
	else
	{
		if (stats->disorder_metric < 0.2)
			ft_printf("[bench] strategy: Adaptive / O(n2)\n");
		else if (stats->disorder_metric >= 0.2 && stats->disorder_metric < 0.5)
			ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf("[bench] strategy: Adaptive / O(n log n)\n");
	}
	printf("[bench] total_ops: %d\n", stats->total_ops);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", stats->sa, stats->sb,
		stats->ss, stats->pa, stats->pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", stats->ra,
		stats->rb, stats->rr, stats->rra, stats->rrb, stats->rrr);
}

int	main(int ac, char **av)
{
	int		start;
	char	**args;
	t_stack	*stack_a;
	t_flags	flags;
	t_stats	*stats;

	stack_a = NULL;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	start = 1;
	flags = ft_get_flags(av, &start);
	if (ac - start == 1)
		args = ft_split(av[start], ' ');
	else
		args = av + start;
	if (!ft_check_args(args))
		return (0);
	stack_a = ft_init_stack(args);
	stats = ft_init_stats(&flags);
	ft_init_index(stack_a, ft_list_size(stack_a));

	if(!stats)
	return (0);
	stats->disorder_metric = ft_compute_disorder(&stack_a);
	if (!stats->disorder_metric)
	{
		free(stats);
		return (0);
	}
	ft_select_algo(&stack_a, &flags, stats);
	if (ac - start == 1)
	ft_freearr(args, ft_countword(av[start], ' '));
	if(flags.bench)
	ft_print_bench(&flags,stats);
	ft_free_stacks(&stack_a, NULL,stats);
		// faire des verifs dans le free du coup
	
	return (0);
}
