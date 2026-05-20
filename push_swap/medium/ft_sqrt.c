#include "../push_swap.h"

int	ft_sqrt(int n)
{
	int	x;

	x = n;
	while (x * x > n)
		x = (x + (n / x)) / 2;
	printf("%d", x);
	return (x);
}