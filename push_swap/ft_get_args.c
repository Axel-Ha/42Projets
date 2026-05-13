#include "push_swap.h"

t_flags ft_get_flags(char **flag, int *start)
{
    t_flags flags;
    int     found;

    flags.algo = 4;
    flags.bench = 0;
    while (flag[*start] && flag[*start][0] == '-')
    {
        found = 0;
        if (ft_strncmp("--simple", flag[*start], 9) == 0)
        {
            flags.algo = 1;
            found = 1;
        }
        else if (ft_strncmp("--medium", flag[*start], 9) == 0)
        {
            flags.algo = 2;
            found = 1;
        }
        else if (ft_strncmp("--complex", flag[*start], 10) == 0)
        {
            flags.algo = 3;
            found = 1;
        }
        else if (ft_strncmp("--adaptive", flag[*start], 11) == 0)
        {
            flags.algo = 4;
            found = 1;
        }
        else if (ft_strncmp("--bench", flag[*start], 8) == 0)
        {
            flags.bench = 1;
            found = 1;
        }
        if (!found)
            break ;
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
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (ft_check_duplicate(args) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
