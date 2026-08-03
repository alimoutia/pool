#include <unistd.h>

int indexxxx(char c, char *alpha_maj, char *alpha_min)
{
	int i = 0;
	while (alpha_min[i])
	{
		if (alpha_min[i] == c)
		{
			return (i);
		}
		i++;
	}
	i = 0;
	while (alpha_maj[i] == c)
	{
		if (alpha_maj[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char alph_maj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alph_min[] = "abcdefghijklmnopqrstuvwxyz";
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') 
			|| (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
			{
				while (j < indexxxx(argv[1][i], alph_maj, alph_min))
				{
					write(1, &argv[1][i], 1);
					j++;
				}
				j = 0;
			}
		write(1, &argv[1][i], 1);
		i++;
	}
	return 0;
}