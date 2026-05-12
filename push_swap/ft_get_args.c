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

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (ft_issign(nbr[i]) && nbr[i + 1] != '\0')
		i++;
	if (!ft_isdigit(nbr[i]))
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_ranges(char *nbr)
{
	long	n;

	n = ft_atoi(nbr);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
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
	if (ft_check_duplicate(args))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
