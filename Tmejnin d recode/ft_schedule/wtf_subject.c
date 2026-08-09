#include <unistd.h>

typedef struct s_range {
	int	start;
	int	end;
}	t_range;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	print_2digits(int n)
{
	char	d1;
	char	d2;

	d1 = (n / 10) + '0';
	d2 = (n % 10) + '0';
	write(1, &d1, 1);
	write(1, &d2, 1);
}

void	print_range(int start, int end)
{
	print_2digits(start / 60);
	write(1, ":", 1);
	print_2digits(start % 60);
	write(1, "-", 1);
	print_2digits(end / 60);
	write(1, ":", 1);
	print_2digits(end % 60);
	write(1, "\n", 1);
}

int	parse_range(char *str, int *start, int *end)
{
	int	h1;
	int	m1;
	int	h2;
	int	m2;

	if (ft_strlen(str) != 11)
		return (0);
	if (!is_digit(str[0]) || !is_digit(str[1]) || str[2] != ':'
		|| !is_digit(str[3]) || !is_digit(str[4]) || str[5] != '-'
		|| !is_digit(str[6]) || !is_digit(str[7]) || str[8] != ':'
		|| !is_digit(str[9]) || !is_digit(str[10]))
		return (0);
	h1 = (str[0] - '0') * 10 + (str[1] - '0');
	m1 = (str[3] - '0') * 10 + (str[4] - '0');
	h2 = (str[6] - '0') * 10 + (str[7] - '0');
	m2 = (str[9] - '0') * 10 + (str[10] - '0');
	if (h1 < 0 || h1 > 23 || m1 < 0 || m1 > 59)
		return (0);
	if (h2 < 0 || h2 > 23 || m2 < 0 || m2 > 59)
		return (0);
	*start = h1 * 60 + m1;
	*end = h2 * 60 + m2;
	if (*start >= *end)
		return (0);
	return (1);
}

void	sort_ranges(t_range *ranges, int count)
{
	int		i;
	int		j;
	t_range	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (ranges[j].start > ranges[j + 1].start)
			{
				tmp = ranges[j];
				ranges[j] = ranges[j + 1];
				ranges[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_range	ranges[1024];
	int		i;
	int		cur_start;
	int		cur_end;

	if (argc == 1)
	{
		ft_putstr("No range provided.\n");
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (!parse_range(argv[i + 1], &ranges[i].start, &ranges[i].end))
		{
			ft_putstr("Error: Invalid range\n");
			return (0);
		}
		i++;
	}
	sort_ranges(ranges, argc - 1);
	cur_start = ranges[0].start;
	cur_end = ranges[0].end;
	i = 1;
	while (i < argc - 1)
	{
		if (ranges[i].start <= cur_end)
		{
			if (ranges[i].end > cur_end)
				cur_end = ranges[i].end;
		}
		else
		{
			print_range(cur_start, cur_end);
			cur_start = ranges[i].start;
			cur_end = ranges[i].end;
		}
		i++;
	}
	print_range(cur_start, cur_end);
	return (0);
}