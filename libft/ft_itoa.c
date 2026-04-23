#include "libft.h"

char	*ft_putnbr(char *s, int n, int *pos)
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
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
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
    long    nb;

	i = 0;
    nb = n;
	newString = malloc(ft_getlen(nb) + 1);
	if (!newString)
		return (NULL);
	if (nb < 0)
	{
		newString[i] = '-';
		i++;
		nb *= -1;
	}
	ft_putnbr(newString, nb, &i);
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
