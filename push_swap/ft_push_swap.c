#include "push_swap.h"

int	main(int ac, char **av)
{
	t_flags flag;
	int start;
	char **args;

	if(ac < 2)
	{
		write(2,"Error\n",6);
		return (0);
	}
	start = 1;
	flag = ft_get_args(av,&start);
	/*Verifier la taille */
	if(ac - start == 1)
		printf("%s",av[1]);
		// args = ft_split(av[start], '');
	else
		args = av + start;
	printf("%s",args);

}