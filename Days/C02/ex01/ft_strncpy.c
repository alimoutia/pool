/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:59:41 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/25 10:36:15 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <unistd.h>

int main()
{
	char dest[45];
	char src[] = "Hello world!";
	unsigned int n = 11;
	int i = 0;
	
	ft_strncpy(dest, src, n);
	
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return 0;
}*/
