#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}

	int size;
	int i;

	i = 0;
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);

	if (!*range)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}
