#include "push_swap.h"

int	ft_free_stacks(t_stack **stack_a, t_stack **stack_b, t_stats *stats, t_flags *flags)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	free(stats);
	free(flags);
	
	return (0);
}