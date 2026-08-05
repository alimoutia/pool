#include <unistd.h>

int teeked(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] != 127)
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2 || !teeked(argv[1]))
	{
		write(1, "\n", 1);
		return 0;
	}
	int word_printed = 0;
	int i = 0;
	while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		i++;
	while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	word_printed++;
	while (argv[1][i])
	{
		while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		if (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t' && word_printed == 1)
			write(1, "   ", 3);
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
