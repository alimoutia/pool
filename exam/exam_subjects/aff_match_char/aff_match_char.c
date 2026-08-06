#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	if (argc != 3)
	{
		write(1, "x\n", 2);
		return 0;
	}

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == argv[2][0])
		{
			write(1, &argv[1][i], 1);
			write(1, "\n", 1);
			return 0;
		}
		i++;
	}
	
	write(1, "\n", 1);
	return 0;
}