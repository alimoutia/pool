/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:53:10 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/25 16:12:07 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32;
		else if ((str[i] >= 'a' && str[i] <= 'z') 
			&& !((str[i - 1] >= 'a' && str[i - 1] <= 'z') 
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9')) 
				str[i] -= 32;
		i++;
	}
	return (str);
}

//#include <unistd.h>

/* int main()
{
	int i = 0;
	char str[] = "    hHLelp)o ,, KElls66llfk/l <<dddd55k  Ld a";

	ft_strcapitalize(str);

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return 0;
}
 */