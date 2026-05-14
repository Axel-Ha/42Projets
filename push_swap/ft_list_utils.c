/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:13:06 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/14 14:17:33 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_listlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_listnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	ft_list_size(t_stack *stack)
{
	t_stack	*current;
	int		count;

	if (!stack)
		return (0);
	current = stack;
	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_listlast(*lst);
	tmp->next = new;
}
