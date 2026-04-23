#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
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
/*
int	main(void)
{
	printf("%d\n", ft_atoi("      -12a3"));
	printf("%d\n", atoi("     -12a3"));
	return (0);
}
*/
