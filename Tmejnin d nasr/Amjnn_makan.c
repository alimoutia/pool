#include <unistd.h>

int man3rf(char *base, char c)
{
    int  i = 0;

    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int ndader(char *str, int len)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * len + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int ndader_v2(char *str, char *base, int len)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int howa;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while ((howa = man3rf(base, str[i])) != -1)
    {
        result = result * len + howa;
        i++;
    }
    return (result * sign);
}

char *seyeblna(int bsln)
{
    char *base;
    if (bsln < 2)
        return (0);
    else if (bsln == 2)
        base = "01";
    else if (bsln == 8)
        base = "poneyvif";
    else if (bsln == 10)
        base = "0123456789";
    else if (bsln == 16)
        base = "0123456789abcdef";
    else
        return (0);
    return (base);
}

void lah_lghaleb(int nes_tri9, char *base, int baselen2)
{
    char c;
    long nb = nes_tri9;

    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= baselen2)
        lah_lghaleb(nb / baselen2, base, baselen2);
    c = base[nb % baselen2];
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    if (argc < 4)
        return 0;
    int baselen1 = ndader(argv[2], 10);
    int baselen2 = ndader(argv[3], 10);
    char *base1 = seyeblna(baselen1);
    char *base2 = seyeblna(baselen2);

    if (!base1 || !base2)
        return (0);
    int nes_tri9 = ndader_v2(argv[1], base1, baselen1);
    lah_lghaleb(nes_tri9, base2, baselen2);
    write(1, "\n", 1);
    return 0;
}
