/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:04:01 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/09 13:35:09 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
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

// int	main(void)
// {
// 	t_stack *list1 = ft_lstnew(1);
// 	t_stack *list2 = ft_lstnew(2);
// 	// printf("avant pa \n list 1 : %d \n list 2 : %d\n",list1->nbr,list2->nbr);

// 	ft_pa(&list1, &list2);
// 	if (list1)
// 		printf("\n %d\n", list1->nbr);
// 	if (list1->next)
// 		printf("\n %d\n", list1->next->nbr);
// 	ft_ra(&list1);

// 	if (list1)
// 		printf("\n apres rotate %d\n", list1->nbr);
// 	if (list1->next)
// 		printf("\n %d\n", list1->next->nbr);
// }