/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:34:16 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/09 13:59:54 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*beforelast;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	beforelast = *stack;
	while (beforelast->next->next != NULL)
		beforelast = beforelast->next;
	last = beforelast->next;
	last->next = *stack;
	beforelast->next = NULL;
	*stack = last;
}

void ft_rra(t_stack **stack_a)
{
	ft_rotate_reverse(stack_a);
	ft_printf("sa\n");
}

void ft_rrb(t_stack **stack_b)
{
	ft_rotate_reverse(stack_b);
	ft_printf("sb\n");
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_reverse(stack_a);
	ft_rotate_reverse(stack_b);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_stack *a = ft_lstnew(1);
	a->next = ft_lstnew(2);
	a->next->next = ft_lstnew(3);

	printf("Avant Rotate ");
	printf("Sommet : %d\n", a->nbr);
	printf("Milieu : %d\n", a->next->nbr);
	printf("Fin    : %d\n", a->next->next->nbr);

	ft_rra(&a);

	printf("\nAprès Reverse Rotate\n");
	printf("Nouveau Sommet : %d\n", a->nbr);
	printf("Nouveau Milieu : %d\n", a->next->nbr);
	printf("Nouvelle Fin : %d\n", a->next->next->nbr);

	return (0);
}