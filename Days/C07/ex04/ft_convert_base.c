#include <stdlib.h>

int		ft_strlen(char *str);
int		checkbase(char *base);
long	ft_parse_nbr(char *nptr, char *base_from);

int	get_nblen(long nb, int base_len)
{
	int	len;

	if (nb <= 0)
		len = 1;
	else
		len = 0;
	while (nb != 0)
	{
		len++;
		nb /= base_len;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	val;
	int		len;
	int		bslen;
	char	*str;

	if (!nbr || !checkbase(base_from) || !checkbase(base_to))
		return (NULL);
	val = ft_parse_nbr(nbr, base_from);
	bslen = ft_strlen(base_to);
	len = get_nblen(val, bslen);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (val == 0)
		str[0] = base_to[0];
	if (val < 0)
	{
		str[0] = '-';
		val = -val;
	}
	while (val > 0)
	{
		str[--len] = base_to[val % bslen];
		val /= bslen;
	}
	return (str);
}
