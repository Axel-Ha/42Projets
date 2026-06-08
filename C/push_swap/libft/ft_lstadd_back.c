/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:19 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 14:07:49 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/*
int main(void)
{
	t_list *list = ft_lstnew("1er");
	t_list *test2 = ft_lstnew("2eme");
	
	ft_lstadd_back(&list, test2);
	t_list *tmp = list;
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
*/
