static int get_digit_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int digit;

    if (!str || str_base < 2 || str_base > 16)
        return (0);
    // 1. Skip leading whitespaces
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    // 2. Handle optional single sign
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    // 3. Convert characters to int while they are valid digits for str_base
    while (str[i])
    {
        digit = get_digit_value(str[i]);
        if (digit < 0 || digit >= str_base)
            break;
        result = result * str_base + digit;
        i++;
    }
    return (result * sign);
}