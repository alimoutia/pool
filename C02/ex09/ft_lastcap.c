
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int i = 0;
	write(1, "Before : ", 9);

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 2);
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
		if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (!((str[i + 1] >= 'a' && str[i + 1] <= 'z') 
					|| (str[i + 1] >= 'A' && str[i + 1] <= 'Z')))
						str[i] -= 32;
			}
		i++;
	}
	i = 0;
	write(1, "After : ", 8);

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 2);
	return 0;
}

int main()
{
	char *str = "   HJefJJ69 jjk utu- j99k  ";

	ft_strcapitalize(str);
	return 0;
}