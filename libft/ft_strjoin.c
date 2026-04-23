#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	lens1;
	size_t	lentotal;

	lens1 = ft_strlen(s1);
	lentotal = lens1 + ft_strlen(s2);
	result = malloc(lentotal);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, lens1 + 1);
	ft_strlcat(result, s2, lentotal + 1);
	return (result);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("jetest", "suis"));
	return (0);
}
*/