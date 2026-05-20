#include "../push_swap.h"

int		ft_find_max_index(t_stack *stack_b)
{
	int max;

	max = stack_b->index;
	while (stack_b)
	{
		if (max < stack_b->index)
			max = stack_b->index;
		stack_b = stack_b->next;
	}
	return (max);
}
int	ft_find_pos(t_stack *stack_b, int id)
{
	int	pos;

	pos = 0;
	while (stack_b)
	{
		if (stack_b->index == id)
			return (pos);
		stack_b = stack_b->next;
		pos++;
	}
	return (0);
}
void	ft_reconstruct(t_stack **stack_a, t_stack **stack_b,
		t_stats *stats)
{
	int	idx_max;
	int	pos;
	int	moves;

	while (*stack_b)
	{
		idx_max = ft_find_max_index(*stack_b);
		pos = ft_find_pos(*stack_b, idx_max);
		if (pos < ft_list_size(*stack_b) /  2)
			while (pos--)
				ft_rb(stack_b, stats);
		else
		{
			moves = ft_list_size(*stack_b) - pos;
			while (moves--)
				ft_rrb(stack_b, stats);
		}
		ft_pa(stack_a, stack_b, stats);
	}
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, int list_size,
		t_stats *stats)
{
	int chunk_size;
	int nb_chunk;
	int chunk;
	int idx_min;
	int idx_max;

	chunk_size = ft_sqrt(list_size);
	nb_chunk = (list_size / chunk_size) + 1;
	chunk = -1;
	while (++chunk < nb_chunk)
	{
		idx_min = chunk * chunk_size;
		idx_max = idx_min + chunk_size;
		while (ft_list_size(*stack_a) > 0)
		{
			if ((*stack_a)->index >= idx_min && (*stack_a)->index < idx_max)
				ft_pb(stack_a, stack_b, stats);
			else
				ft_ra(stack_a, stats);
			if (ft_list_size(*stack_b) == idx_max)
				break ;
		}
	}
	ft_reconstruct(stack_a, stack_b, stats);
}