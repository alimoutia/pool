#include <unistd.h>

int ft_atoi(char *nb)
{
	int i = 0;
	int result = 0;
	int sign = 1;

	if (nb[i] == '-' || nb[i] == '+')
	{
		sign = -sign;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	return (result * sign);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Usage: ./ft_dice <1-6> [1-6] ...\n", 33);
		return 0;
	}
	int i = 1;
	while (i < argc)
	{
		if (!(ft_atoi(argv[i]) >= 1 && ft_atoi(argv[i]) <= 6))
		{
			write(1, "Error: Invalid die\n", 19);
			return 0;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		write(1, "+-------+", 9);
		i++;
	}
	write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		if (ft_atoi(argv[i]) == 1)
			write(1, "|       |", 9);
		if (ft_atoi(argv[i]) == 2 || ft_atoi(argv[i]) == 3)
			write(1, "| o     |", 9);
		if (ft_atoi(argv[i]) == 4 || ft_atoi(argv[i]) == 5 || ft_atoi(argv[i]) == 6)
			write(1, "| o   o |", 9);
		i++;
	}
	write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		if (ft_atoi(argv[i]) == 2 || ft_atoi(argv[i]) == 4)
			write(1, "|       |", 9);
		if (ft_atoi(argv[i]) == 1 || ft_atoi(argv[i]) == 3 || ft_atoi(argv[i]) == 5)
			write(1, "|   o   |", 9);
		if (ft_atoi(argv[i]) == 6)
			write(1, "| o   o |", 9);
		i++;
	}
	write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		if (ft_atoi(argv[i]) == 1)
			write(1, "|       |", 9);
		if (ft_atoi(argv[i]) == 2 || ft_atoi(argv[i]) == 3)
			write(1, "|     o |", 9);
		if (ft_atoi(argv[i]) == 4 || ft_atoi(argv[i]) == 5 || ft_atoi(argv[i]) == 6)
			write(1, "| o   o |", 9);
		i++;
	}
	write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		write(1, "+-------+", 9);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}