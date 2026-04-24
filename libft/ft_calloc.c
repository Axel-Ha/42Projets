#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void *result;
	size_t total_size;

	if (elementCount != 0)
		return (NULL);
	if ((elementCount * elementSize) / elementSize > elementSize)
		return (NULL);
	total_size = elementCount * elementSize;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total_size);
	return (result);
}