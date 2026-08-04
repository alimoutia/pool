/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:11:34 by amoutia           #+#    #+#             */
/*   Updated: 2026/08/05 00:26:20 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	hseb_tol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*copy_lina(char *strr)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (hseb_tol(strr) + 1));
	if (!ptr)
		return (NULL);
	while (strr[i])
	{
		ptr[i] = strr[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	if (ac < 0)
		return (NULL);
	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = hseb_tol(av[i]);
		arr[i].str = av[i];
		arr[i].copy = copy_lina(av[i]);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}
