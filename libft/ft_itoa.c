#include "libft.h"

void	ft_putnbr(char *s, int n, int *pos)
{
	if (n > 9)
	{
		ft_putnbr(s, n / 10, pos);
		ft_putnbr(s, n % 10, pos);
	}
	else
	{
		s[*pos] = n + '0';
		(*pos)++;
	}
}

int	ft_getlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*newString;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	newString = malloc(ft_getlen(n) + 1);
	if (!newString)
		return (NULL);
	if (n < 0)
	{
		i++;
		newString[i] = '-';
		n *= -1;
	}
	ft_putnbr(newString, n, &i);
	newString[i] = '\0';
	return (newString);
}

/*
int	main(void)
{
	printf("%s", ft_itoa(-123));
	return (0);
}
*/
