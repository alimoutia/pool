/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 09:54:35 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/25 10:39:36 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	sizes;

	i = 0;
	sizes = 0;
	while (src[sizes])
		sizes++;
	if (size == 0)
		return (sizes);
	while (src[i] && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sizes);
}

/*#include <unistd.h>

int main()
{
	char dest[5];
	char src[] = "Hello hi";
	unsigned int size = 5;

	ft_strlcpy(dest, src, size);
	
	int i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return 0;
}*/