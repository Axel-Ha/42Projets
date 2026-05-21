#include "push_swap.h"

void	ft_init_index(t_stack *stack, int stack_size)
{
	t_stack	*tmp;
	t_stack	*max_node;

	while (--stack_size)
	{
		tmp = stack;
		max_node = NULL;
		while (tmp)
		{
			if (!tmp->index && (max_node == NULL || tmp->nbr > max_node->nbr))
				max_node = tmp;
			tmp = tmp->next;
		}
		if (max_node)
			max_node->index = stack_size;
	}
}

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

t_stats	*ft_init_stats(t_flags *flag)
{
	t_stats	*stats;

	stats = malloc(sizeof(t_stats));
	if (!stats)
		return (NULL);
	stats->total_ops = 0;
	stats->bench = flag->bench;
	stats->disorder_metric = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
	return (stats);
}

t_flags	*ft_init_flags(void)
{
	t_flags *flags;

	flags = malloc(sizeof(t_stats));
	if (!flags)
		return (NULL);
	flags->bench = 0;
	flags->algo = 4;
	return (flags);
}