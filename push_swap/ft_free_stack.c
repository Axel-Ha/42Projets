#include "push_swap.h"

int	ft_free_stacks(t_stack **stack_a, char **args, t_stats *stats, t_flags *flags)
{
	ft_stack_clear(stack_a);
	free(args);
	free(stats);
	free(flags);
	
	return (0);
}