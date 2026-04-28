/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:25 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/27 14:13:48 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

/*
void ft_delcontent(void *content)
{
	printf("suppression de %s\n",(char *)content);
}

int main(void)
{
	t_list *list = ft_lstnew("1er");
	t_list *test2 = ft_lstnew("2eme");
	t_list *test3 = ft_lstnew("3eme");
	
	ft_lstadd_front(&list, test2);
	ft_lstadd_front(&list, test3);
	ft_lstclear(&list,ft_delcontent);
	if(list == NULL)
		printf("suppression successful");
}
*/
