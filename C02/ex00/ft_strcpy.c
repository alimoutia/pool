/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:49:38 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/25 10:36:02 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <unistd.h>

int main()
{
	char *dest;
	char *src;
	src = "Hello world!";
	int i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	
	ft_strcpy(dest, src);
	
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return 0;
}*/