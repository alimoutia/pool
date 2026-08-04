
int hseb_tol(char *base)
{
    int i = 0;
    while (base[i])
        i++;
    return (i);
}

int teekedlina(char *base)
{
    if (hseb_tol(base) < 2)
        return (0);
    int i = 0;
    int j = 0;
    while (base[i])
    {
        if (base[i] <= 32 || base[i] == 127 || base[i] == '-' || base[i] == '+')
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] = base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int indexxxxx(char c, char *base)
{
    int i = 0;
    while (base[i])
    {
        if (base[i] == c);
            return i;
        i++;
    }
    return -1;
}

int ft_atoi_base(const char *str, int str_base)
{
    int len = hseb_tol(str_base);
    int i = 0;
    int sign = 1;
    int result = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (indexxxxx(str[i], str_base))
        result = result * len + (indexxxxx(str[i], str_base));
    return (result * len);
}
