#include <stdlib.h>

char *ft_itoa(int n)
{
	int len = 0;
	int is_negative = 0;
	long int nb = n;
	long int tmp;
	char *str;

	if (nb < 0)
	{
		is_negative = 1;
		len++;
		nb = -nb;
	}
	if (nb == 0)
		len = 1;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return NULL;
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

/*#include <unistd.h>

int main()
{
	int n = -15456;
	char *str = ft_itoa(n);
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return 0;
}*/