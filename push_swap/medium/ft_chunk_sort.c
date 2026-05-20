#include "../push_swap.h"

// int	find_min_nbr(t_stack *stack_a)
// {
// 	int	min_val;
// 	int	min_id;
// 	int	current_id;

// 	min_val = stack_a->nbr;
// 	min_id = 0;
// 	current_id = 0;
// 	while (stack_a)
// 	{
// 		if (min_val > stack_a->nbr)
// 		{
// 			min_val = stack_a->nbr;
// 			min_id = current_id;
// 		}
// 		current_id++;
// 		stack_a = stack_a->next;
// 	}
// 	return (min_id);
// }

// void	ft_move_min_top(t_stack **stack_a, int size, t_stats *stats)
// {
// 	int	id_min;
// 	int	moves;

// 	id_min = find_min_nbr(*stack_a);
// 	if (id_min == 0)
// 		return ;
// 	if (id_min < size / 2)
// 		while (id_min--)
// 			ft_ra(stack_a, stats);
// 	else
// 	{
// 		moves = size - id_min;
// 		while (moves--)
// 			ft_rra(stack_a, stats);
// 	}
// }

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, int list_size, t_stats *stats)
{
	int chunk_size = ft_sqrt(list_size);
	int nb_chunk = (list_size / chunk_size) + 1;
	int chunk = 0;
	int idx_min = 0;
	int idx_max = 0;
	int push = 0;
	int left = list_size;
	int i = list_size;
	while (chunk < nb_chunk)
	{
		idx_min = chunk * chunk_size;
		idx_max = chunk + idx_min;
		push = 0;
		while (push < chunk_size && (*stack_a))
		{
			if (((*stack_a)->index >= idx_min) && (*stack_a)->index <= idx_max)
			{
				ft_move_min_top(stack_a, left, stats);
				ft_pb(stack_a, stack_b, stats);
				left--;
			}
		}
		chunk++;
	}
	while (i--)
		ft_pa(stack_a, stack_b, stats);
}