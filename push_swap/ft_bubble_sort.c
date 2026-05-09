#include "push_swap.h"

void	ft_bubble_sort(t_stack **stack_a, int size)
{
	int	i;
	int	j;
	int	k;
	int	sorted;

	i = 0;
	while (i < size - 1)
	{
		sorted = 1;
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			{
				ft_sa(stack_a);
				sorted = 0;
			}
			ft_ra(stack_a);
			j++;
		}
		k = 0;
		while (k < size - 1 - i)
		{
			ft_rra(stack_a);
			k++;
		}
		if (sorted == 1)
			break ;
		i++;
	}
}

// t_stack	*ft_lstnew(int content)
// {
// 	t_stack	*node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->nbr = content;
// 	node->next = NULL;
// 	return (node);
// }

// void	ft_lst_print(t_stack **stack)
// {
// 	t_stack	*a;

// 	a = *stack;
// 	while (a)
// 	{
// 		printf("%d\n", a->nbr);
// 		a = a->next;
// 	}
// }

// int	main(void)
// {
// 	t_stack *a = ft_lstnew(2);
// 	a->next = ft_lstnew(1);
// 	a->next->next = ft_lstnew(3);
// 	a->next->next->next = ft_lstnew(6);
// 	a->next->next->next->next = ft_lstnew(5);
// 	a->next->next->next->next->next = ft_lstnew(8);

// 	// printf("Avant bubble sort\n");
// 	// ft_lst_print(&a);
// 	ft_bubble_sort(&a,5);
// 	// printf("apres bubble sort\n");
// 	// ft_lst_print(&a);

// 	return (0);
// }