#include <stdlib.h>

int nblen(long int nb, int len)
{
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char *makestr(long int nb, int len, char *ptr)
{
	while (nb > 0)
	{
		len--;
		ptr[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}

char *ft_itoa(int n)
{
	char *ptr;
	long int nb;
	int len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb > 0)
		len = nblen(nb, len);
	if (nb == 0)
		len = 1;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (nb == 0)
		ptr[0] = '0';
	ptr = makestr(nb, len, ptr);
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
