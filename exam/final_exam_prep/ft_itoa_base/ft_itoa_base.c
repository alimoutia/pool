#include <stdlib.h>

int is_discimal(int base)
{
	int is_dis;

	is_dis = 0;
	if (base < 2 || base > 16)
		return (0);
	if (base == 10)
	{
		is_dis = 1;
		return (is_dis);
	}
	return (is_dis);
}

char *makestr(unsigned int nb, int base, int len, char *nbr)
{
	char *el_base;

	el_base = "0123456789ABCDEF";
	if (nb == 0)
		nbr[0] = el_base[nb % base];
	while (nb > 0)
	{
		len--;
		nbr[len] = el_base[nb % base];
		nb /= base;
	}
	return (nbr);
}
int is_negative(int value)
{
	if (value < 0)
		return (1);
	return (0);
}

int lennb(long int value, int base)
{
	unsigned int tmp;
	int len;

	tmp = value;
	len = 0;
	while (tmp > 0)
	{
		len++;
		tmp /= base;
	}
	if (value == 0)
		len = 1;
	return (len);
}

char *ft_itoa_base(int value, int base)
{
	int len;
	long int neg;
	unsigned int nb;
	char *nbr;

	neg = value;
	len = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (is_discimal(base) && is_negative(value))
	{
		len++;
		neg = -neg;
	}
	nb = neg;
	len = len + lennb(neg, base);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	nbr = makestr(nb, base, len, nbr);
	if (is_negative(value) && is_discimal(base))
		nbr[0] = '-';
	return (nbr);
}
