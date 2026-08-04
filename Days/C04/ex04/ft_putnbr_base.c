/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 16:56:10 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/28 11:48:42 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int	len;
	int	i;
	int	j;

	i = 0;
	len = dakchi(base);
	if (len < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long int	nb;
	char		c;

	if (!checkbase(base))
		return ;
	nb = nbr;
	len = dakchi(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= len)
		ft_putnbr_base(nb / len, base);
	c = base[nb % len];
	write(1, &c, 1);
}
