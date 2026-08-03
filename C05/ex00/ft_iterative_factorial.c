/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:38:19 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/28 16:49:14 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

/*#include "ft_putnbr.c"

int main()
{
	int nb = 100;
	
	ft_putnbr(ft_iterative_factorial(nb));
	return (0);
}*/