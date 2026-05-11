#include "push_swap.h"

t_flags	ft_get_args(char **av, int *start)
{
	t_flags	flags;

	flags.algo = 4;
	flags.bench = 0;
	while (av[*start] && av[*start][0] == '-')
	{
		if (ft_strncmp("--simple", av[*start], 9) == 0)
			flags.algo = 1;
		if (ft_strncmp("--medium", av[*start], 9) == 0)
			flags.algo = 2;
		if (ft_strncmp("--complex", av[*start], 10) == 0)
			flags.algo = 3;
		if (ft_strncmp("--adaptive", av[*start], 11) == 0)
			flags.algo = 4;
		if (ft_strncmp("--bench", av[*start], 8) == 0)
			flags.bench = 1;
		(*start)++;
	}
	return (flags);
}

int	ft_get_nbrs(int **av, int pos)
{
    return (0);
}
