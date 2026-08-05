#include <stdlib.h>

typedef struct s_stock_str {
	int size;
	char *str;
	char *copy;
}   t_stock;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int main(int argc, char **argv)
{
	t_stock *arr;

	arr = ft_strs_to_tab(argc, argv);
	ft_show_tab(arr);

	int i = 0;
	while (arr[i].str != NULL)
	{
		free(arr[i].copy);
		i++;
	}
	free(arr);
	return 0;
}
