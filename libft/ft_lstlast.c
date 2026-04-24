#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *last;

	if (lst->next == NULL)
		return (lst);
	last = lst->next;
	while (lst != NULL)
		last = lst->next;
	return (last);
}