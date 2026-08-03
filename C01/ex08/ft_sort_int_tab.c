/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:16:35 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/22 13:23:59 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int **tab, int **size)
{
	int j;
	int temp;
	
	j = 0;
	while (j < **size - 1)
	{
		if ((*tab)[j] > (*tab)[j + 1])
		{
			temp = (*tab)[j];
			(*tab)[j] = (*tab)[j + 1];
			(*tab)[j + 1] = temp;
			j = 0;
		}
		else
			j++;
	}	
}

# include <unistd.h>

int main(void)
{
	int tab1[] = {5, 2, 0, 2, 1, 8};
	int *tab = tab1;

	int size2 = 6;
	int *size1 = &size2;

	ft_sort_int_tab(&tab, &size1);
	
	int i = 0;
	while (i < size2)
	{
		char c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	return 0;
}
