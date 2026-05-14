#include "push_swap.h"

void	ft_select_algo(t_stack **stack_a, t_stack **stack_b, t_flags *flags,
		float disorder_metric)
{
	// t_stats stats;
	// stats.
	if (!flags)
		return ;
	if (flags->algo == 1)
		ft_select_sort(stack_a, stack_b, ft_list_size(*stack_a));
	// else if (flags.algo == 2)
	// ft_chunk_sort();
	// ft_printf("test");
	// else if (flags.algo == 3)
	// ft_radix_sort();
	else
	{
		if (disorder_metric < 0.2)
			ft_select_sort(stack_a, stack_b, ft_list_size(*stack_a));
		// else if(disorder_metric >= 0.2 && disorder_metric < 0.5)
		// 	// ft_chunk_sort();
		// else
		// 	ft_radix_sort();
		// if (flags.bench)
		// 	print_bench();
	}
}

int	main(int ac, char **av)
{
	int		start;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flag;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	start = 1;
	flag = ft_get_flags(av, &start);
	if (ac - start == 1)
		args = ft_split(av[start], ' ');
	else
		args = av + start;
	if (!ft_check_args(args))
		return (0);
	stack_a = ft_init_stack(args);
	if (!ft_compute_disorder(&stack_a))
		return (0);
	ft_select_algo(&stack_a, &stack_b, &flag, ft_compute_disorder(&stack_a));
	if (ac - start == 1)
		ft_freearr(args, ft_countword(av[start], ' '));
	ft_free_stacks(&stack_a, &stack_b);
	return (0);
}
