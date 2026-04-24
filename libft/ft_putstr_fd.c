#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
int	main(void)
{
	ft_putstr_fd("Je suis ", 1);
	return (0);
}
*/