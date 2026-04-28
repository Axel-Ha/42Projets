/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:34 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 14:17:09 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int main(void)
{
	t_list *list = ft_lstnew("test");
	t_list *test2 = ft_lstnew("je suis premier");
	t_list *test3 = ft_lstnew("3eme");
	
	ft_lstadd_front(&list, test3);
	ft_lstadd_back(&list, test2);
	t_list *tmp = ft_lstlast(list);
	printf("%s\n", tmp->content);
}
*/
