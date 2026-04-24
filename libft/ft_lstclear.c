#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current);
		free(current);
		current = next
	}
	lst = NULL;
}