/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:31:44 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/28 16:50:08 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb)
	{
		if (i <= 46340 && i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*#include "ft_putnbr.c"

int main()
{
	int nb = 16;
	
	ft_putnbr(ft_sqrt(nb));
	return (0);
}*/