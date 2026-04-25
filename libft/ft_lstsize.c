#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}