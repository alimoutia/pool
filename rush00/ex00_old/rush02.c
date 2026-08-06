/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:33:36 by dsaib             #+#    #+#             */
/*   Updated: 2026/07/18 14:54:08 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printa(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x -1)
			ft_putchar('A');
		else 
			ft_putchar('B');
		i ++;
	}
	ft_putchar('\n');
}

void	printb(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar('B');
		else 
			ft_putchar(' ');
		i ++;
	}
	ft_putchar('\n');
}

void	rush02(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			printa(x);
		else
			printb(x);
		i ++;
	}
}
