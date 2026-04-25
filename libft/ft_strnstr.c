#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		while (str1[i + j] == str2[j] && str1[i + j] && i + j < len)
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
/*
int	main(void)
{
	const char *largestring = "Bar Fah ";
	const char *smallstring = "Bar";

    printf("%s",ft_strnstr(largestring, smallstring, 4));
    printf("%s",strnstr(largestring, smallstring, 8));
	return (0);
}
*/
