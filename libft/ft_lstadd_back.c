#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !new)
		return ((NULL));
	if (*lst == NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	last->next = *lst;
	while (last != NULL)
		last = last->next;
	last->next = new;
	new->next = NULL;
}