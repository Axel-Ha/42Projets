#include "push_swap.h"

t_stack *ft_init_stack(char **args)
{
    t_stack *head;
    t_stack *new;
    int i;

    head = NULL;
    i = 0;
    while (args[i])
    {
        new = ft_lstnew(ft_atoi(args[i]));
        if (!new)
        {
            ft_stack_clear(&head);
            return (NULL);
        }
        ft_lstadd_back(&head, new);
        i++;
    }
    return (head);
}