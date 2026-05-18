#include "push_swap.h"

t_flags	ft_get_flags(char **args, int *start)
{
	t_flags	flag;
	int		found;

	flag.bench = 0;
	flag.algo = 4;
	while (args[*start] && args[*start][0] == '-')
	{
		found = 1;
		if (!ft_strncmp("--simple", args[*start], 9))
			flag.algo = 1;
		else if (!ft_strncmp("--medium", args[*start], 9))
			flag.algo = 2;
		else if (!ft_strncmp("--complex", args[*start], 10))
			flag.algo = 3;
		else if (!ft_strncmp("--adaptive", args[*start], 11))
			flag.algo = 4;
		else if (!ft_strncmp("--bench", args[*start], 8))
			flag.bench = 1;
		else
			found = 0;
		if (!found)
			break ;
		(*start)++;
	}
	return (flag);
}

int	ft_check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_check_nbr(args[i]) || !ft_check_ranges(args[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (!ft_check_duplicate(args))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
