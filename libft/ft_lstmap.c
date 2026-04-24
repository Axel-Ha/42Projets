#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list newList;
    t_list tmp;
    newList = NULL;
    while(lst != NULL)
    {
        tmp = ft_lstnew(f(lst->content));
        if(!tmp)
        {
            ft_lstclear(&new,del);
            return NULL;
        }
        ft_lstadd_back(&new,tmp);
        lst = lst->next;
    }
    return (newList)
}