#include <stdlib.h>

int	hseb_tol(char **strs, int size, char *sep)
{
	int	i;
	int	a;
	int	len;

	i = 0;
	a = 0;
	len = 0;
	while (sep[i])
		i++;
	len = i * (size - 1);
	i = 0;
	while (i < size)
	{
		a = 0;
		while (strs[i][a])
		{
			a++;
			len++;
		}
		i++;
	}
	return (len);
}

char	*seyeblna(char **strs, char *sep, int len, char *str, int size)
{
	int	i;
	int	a;
	int k;

	i = 0;
	a = 0;
	k = 0;
	while (i < size)
	{
		a = 0;
		while (strs[i][a])
			str[k++] = strs[i][a++];
		a = 0;
		if (i < size - 1)
		{
			while (sep[a])
				str[k++] = sep[a++];
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	len = hseb_tol(strs, size, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = seyeblna(strs, sep, len, str, size);
	return (str);
}
