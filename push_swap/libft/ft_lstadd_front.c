/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:21 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/28 10:07:01 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
int main(void)
{
	t_list *list = ft_lstnew("1er");
	t_list *test2 = ft_lstnew("2eme");
	
	ft_lstadd_front(&list, test2);
	t_list *tmp = list;
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
*/
