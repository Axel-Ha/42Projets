#include "libft.h"

char	*ft_strdup(const char *source)
{
	char *res;
	size_t len;
	size_t i; 
    
    len = ft_strlen(source) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
    while(source[i])
    {
        res[i] = source[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}