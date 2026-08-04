#include <stdlib.h>
#include "ft_stock_str.h"

int hseb_tol(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *copy_lina(char *arr, )

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *arr;

	if (ac < 0)
		return (NULL);
	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
}