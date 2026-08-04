/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:53:55 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/29 11:20:41 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dakchi(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	checkbase(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = dakchi(base);
	if (len < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	indexxx(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	len;

	if (!checkbase(base))
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	len = dakchi(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (indexxx(str[i], base) != -1)
	{
		result = result * len + indexxx(str[i], base);
		i++;
	}
	return (result * sign);
}

/*#include "ft_putnbr.c"

int main()
{
	char str[] = "   -+--++-010101";
	char base[] = "0123456789abcdef";
	ft_putnbr(ft_atoi_base(str, base));
	return(0);
}*/