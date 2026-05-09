#include "push_swap.h"

t_stack	*ft_init_stack(int **av, int pos)
{
	t_stack *current;
	t_stack *head;

	int i;
	/*check	si les chiffres dans av sont goods
	ft_check_nbrs(int **av);
	regarder si on est av est entre int min et int max
	si pendant le check on a autre chose qu'un nbr return null
	pour au final avoir un error
	*/
	head = NULL;
	while (av[pos])
	{
		if (!head)
		{
			head = ft_lstnew(ft_atoi(av[pos]));
			if (!head)
				return (NULL);
			current = head;
		}
		else
		{
			current->next = ft_lstnew(ft_atoi(av[pos]));
			if (!current->next)
				return (ft_lstclear(&head));
			current = current->next;
		}
		i++;
	}
	return (head);
}