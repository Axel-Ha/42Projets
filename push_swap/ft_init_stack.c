#include "push_swap.h"

t_stack	*ft_init_stack(char **args)
{
	int		i;
	t_stack	*head;
	t_stack	*new;

	head = NULL;
	i = 0;
	while (args[i])
	{
		new = ft_listnew(ft_atoi(args[i]));
		if (!new)
		{
			ft_stack_clear(&head);
			return (NULL);
		}
		ft_add_back(&head, new);
		i++;
	}
	return (head);
}
