#include "push_swap.h"

void	ft_bubble_sort(t_stack **stack_a, int size)
{
	int i;
	int j;
	int sorted;

	i = 0;
	while (i < size - 1)
	{
		sorted = 1;
		j = 0;
		while (j < size - 1)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			{
				ft_sa(stack_a);
				sorted = 0;
			}
			ft_ra(stack_a);
			j++;
		}
		ft_rra(*stack_a);
		if (sorted == 1)
			break ;
		i++;
	}
}