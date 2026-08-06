int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return 0;
	unsigned long i = 1;

	while (i <= n)
	{
		if (i == n)
			return 1;
		i = i * 2;
	}
	return 0;
}

/*#include <unistd.h>

int main()
{
	unsigned int n = 25;
	char c = is_power_of_2(n) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return 0;
}*/