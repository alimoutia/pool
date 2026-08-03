#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	len;
	char *dest;

	len = 0;
	while (src[len])
		len++;

	dest = (char *)malloc(sizeof(char) * (len + 1));

	if (!dest)
		return (NULL);
	
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
