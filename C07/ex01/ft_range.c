#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *array;
	int size;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	
	size = max - min;
	array = (int *)malloc(sizeof(int) * size);

	if (!array)
		return (NULL);
	
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
