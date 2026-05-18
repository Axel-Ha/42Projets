#include "../push_swap.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (first[i] && (first[i] == second[i]) && i < n - 1)
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + result * 10;
		i++;
	}
	return (result * sign);
}
