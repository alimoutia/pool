/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:33:36 by dsaib             #+#    #+#             */
/*   Updated: 2026/07/19 10:54:45 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int x, char a, char b)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x -1)
			ft_putchar(a);
		else 
			ft_putchar(b);
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
		if (i == 0)
			print(x, 'A', 'B');
		else if (i == y - 1)
			print(x, 'C', 'B');
		else
			print(x, 'B', ' ');
		i ++;
	}
}
