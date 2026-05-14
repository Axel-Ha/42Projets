#include "push_swap.h"

int	main(int ac, char **av)
{
	int		start;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flag;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	start = 1;
	flag = ft_get_flags(av, &start);
	if (ac - start == 1)
		args = ft_split(av[start], ' ');
	else
		args = av + start;
	if (!ft_check_args(args))
		return (0);
	stack_a = ft_init_stack(args);
	/*faire une fonction qui va selectionner l'algo 
	directement donner les 2 stacks ig
	ft_select_algo(t_stack stack_a, t_flags flags, int compute_disorder())
	*/
	ft_select_sort(&stack_a,&stack_b, ft_list_size(stack_a));
	
	(void)stack_a;
	(void)stack_b;
	(void)flag;
	return (0);
}
