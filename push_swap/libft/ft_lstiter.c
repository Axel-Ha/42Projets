/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:20:30 by ahalifa           #+#    #+#             */
/*   Updated: 2026/04/28 10:07:03 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}


void ft_toupper2(void *content)
{
	int     i = 0;
    char    *str = content;

    while(*str)
    {
        if (*str >= 'a' && *str <= 'z') 
			*str -= 32;
        i++;
		str++;
    }
}


int main(void)
{
	t_list *list = ft_lstnew(ft_strdup("test"));
    t_list *test2 = ft_lstnew(ft_strdup("je suis premier"));
    t_list *test3 = ft_lstnew(ft_strdup("3eme"));
	
	ft_lstadd_front(&list, test3);
	ft_lstadd_front(&list, test2);
	ft_lstiter(list,&ft_toupper2);
    while(list)
    {
        printf("%s\n", (char *)list->content);
        list = list->next;
    }
    return (0);
}