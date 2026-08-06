/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:22:33 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/20 15:42:37 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);

void	ft_print(int x, char a, char b, char c)
{
	int i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void rush(int x, int y)
{
	int i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			ft_print(x, 'A', 'B', 'C');
		else
			ft_print(x, 'B', ' ', 'B');
		i++;
	}
}
