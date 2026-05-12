#include "push_swap.h"

t_flags	ft_get_flags(char **flag, int *start)
{
	t_flags	flags;

	flags.algo = 4;
	flags.bench = 0;
	while (flag[*start] && flag[*start][0] == '-')
	{
		if (ft_strncmp("--simple", flag[*start], 9) == 0)
			flags.algo = 1;
		if (ft_strncmp("--medium", flag[*start], 9) == 0)
			flags.algo = 2;
		if (ft_strncmp("--complex", flag[*start], 10) == 0)
			flags.algo = 3;
		if (ft_strncmp("--adaptive", flag[*start], 11) == 0)
			flags.algo = 4;
		if (ft_strncmp("--bench", flag[*start], 8) == 0)
			flags.bench = 1;
		(*start)++;
	}
	return (flags);
}

int	ft_check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_check_nbr(args[i]) || !ft_check_ranges(args[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	if (!ft_check_duplicate(args))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
