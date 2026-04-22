#include "libft.h"

void	*calloc(size_t elementCount, size_t elementSize)
{
	void *result;

	result = malloc(elementCount * (sizeof(void)));
    if (!result)
        return (NULL);
	result = ft_memset(result, 0, elementCount * size);
	return (result);
}