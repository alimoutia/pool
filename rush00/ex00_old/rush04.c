/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:33:36 by dsaib             #+#    #+#             */
/*   Updated: 2026/07/18 11:33:39 by dsaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print1(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i == x - 1)
			ft_putchar('C');
		else 
			ft_putchar('B');
		i ++;
	}
	ft_putchar('\n');
}

void	print2(int x)
{
	int		i;

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

void	print3(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('C');
		else if (i == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		i ++;
	}
	ft_putchar('\n');
}

void	rush04(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			print1(x);
		else if (i == y - 1)
			print3(x);
		else
			print2(x);
		i ++;
	}
}
