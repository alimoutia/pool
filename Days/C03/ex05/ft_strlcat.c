/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 09:34:36 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/27 09:27:25 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	j;

	src_len = 0;
	i = 0;
	j = 0;
	dest_len = 0; 
	while (src[src_len])
		src_len++;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len >= size)
		return (size + src_len);
	j = dest_len;
	while (src[i] && i < size - dest_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[dest_len] = '\0';
	return (dest_len + src_len);
}
