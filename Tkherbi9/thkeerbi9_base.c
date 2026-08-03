#include <unistd.h>

// putnbr

void	sir_3la_lah(int nb)
{
	char c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		sir_3la_lah(nb /10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

// atoi

int awdi_slak(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// putnbr_base

int dakchi(char *base)
{
	int i = 0;

	while (base[i])
		i++;
	return(i);
}

int baraje(char *base)
{
	int i = 0;
	int j = i + 1;

	if (dakchi(base) < 2)
		return (0);
	if (base[i] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	skippi_a_abdesami3(int nbr, char *base)
{
	long int	nb = nbr;
	char	c;
	int	len = dakchi(base);

	if (!baraje(base))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= len)
		skippi_a_abdesami3(nb / len, base);
	c = base[nb % len];
	write(1, &c, 1);
}

// atoi_base

int dakchi_v2(char *base)
{
	int i = 0;

	while (base[i])
		i++;
	return(i);
}

int baraje_v2(char *base)
{
	int i = 0;
	int j = i + 1;

	if (base[i] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int indexxxx(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int lah_ya_wdi(char *str, char *base)
{
	int i;
	int sign;
	int result;
	int len;

	if (!baraje_v2(base))
		return (0);
	if (dakchi_v2(base) < 2)
		return (0);
	len = dakchi_v2(base);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (indexxxx(str[i], base) != -1)
	{
		result = result * len + indexxxx(str[i], base);
		i++;
	}
	return (result * sign);
}
