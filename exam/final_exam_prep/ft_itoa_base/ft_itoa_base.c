#include <stdlib.h>

int checkbase(int base)
{
	if (base < 2 || base > 16)
		return (-1);
	return (0);
}

char *makestr(long int nb, int base, int len, char *str)
{
	char *bbase;

	bbase = "0123456789ABCDEF";
	if (nb == 0)
	{
		str[0] = bbase[0];
		return (str);
	}
	while (nb != 0)
	{
		len--;
		str[len] = bbase[nb % base];
		nb = nb / base;
	}
	return (str);
}

int nblen(long int nb, int base, int len)
{
	while (nb > 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

char *ft_itoa_base(int value, int base)
{
	char *str;
	unsigned int nb;
	int len;

	if (checkbase(base) == -1)
		return (NULL);
	len = 0;
	nb = value;
	if (value < 0 && base == 10)
	{
		len++;
		nb = (unsigned int)(-value);
	}
	else if (base != 10 && nb < 0)
		nb = (unsigned int)(value);
	len = nblen(nb, base, len);
	if (nb == 0)
		len = 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str = makestr(nb, base, len, str);
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
