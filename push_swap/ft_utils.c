#include "push_swap.h"

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