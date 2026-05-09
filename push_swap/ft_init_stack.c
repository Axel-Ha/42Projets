#include "push_swap.h"

t_stack	*ft_init_stack(int **av)
{
	t_stack *current;
	t_stack *head;

	int i;
	/*check	si les chiffres dans av sont goods
	ft_check_nbrs(int **av);
	*/
	i = 0;
	head = NULL;
	while (av[i])
	{
		if (!head)
		{
			head = ft_lstnew(ft_atoi(av[i]));
			if (!head)
				return (NULL);
			current = head;
		}
		else
		{
			current->next = ft_lstnew(ft_atoi(av[i]));
			if (!current->next)
				return (ft_lstclear(&head));
			current = current->next;
		}
		i++;
	}
	return (head);
}