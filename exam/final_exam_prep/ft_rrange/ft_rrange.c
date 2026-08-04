#include <stdlib.h>

int cholna(int start, int end)
{
	int size;
	if (end >= start)
		size = end - start + 1;
	else if (end < start)
		size = start - end + 1;
	return (size);
}

int *ft_rrange(int start, int end)
{
	int *arr;
	int i = 0;
	int size;
	size = cholna(start, end);
	arr = malloc(sizeof(int) * size);

	if (start == end)
	{
		arr[i] = end;
		return (arr);
	}

	if (end > start)
	{
		while (i < size)
		{
			arr[i] = end;
			i++;
			end--;
		}
	}
	if (end < start)
	{
		while (i < size)
		{
			arr[i] = end;
			i++;
			end++;
		}
	}
	return arr;
}
