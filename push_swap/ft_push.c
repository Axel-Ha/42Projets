/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:12:40 by ahalifa           #+#    #+#             */
/*   Updated: 2026/05/08 17:25:14 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
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
// }