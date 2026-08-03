/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutia <amoutia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:52:21 by amoutia           #+#    #+#             */
/*   Updated: 2026/07/29 12:21:24 by amoutia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	j;

	j = 0;
	while (s1[j] && s2[j] && s1[j] == s2[j])
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}

int	printp(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*srt;

	i = 1;
	while (argv[i] && i < argc -1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			srt = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = srt;
			i = 1;
		}
		else
			i++;
	}
	printp(argv);
	return (0);
}
