# include <unistd.h>

int lbaraje(char *ra9m)
{
    int i = 0;

    while (ra9m[i])
    {
        if (!((ra9m[i] >= '0' && ra9m[i] <= '9') || ra9m[i] == '/' 
            || ra9m[i] == '%' || ra9m[i] == '+' || ra9m[i] == '-' 
            || ra9m[i] == '*' || ra9m[i] == ' ' || ra9m[i] == '\t'))
                return (0);
        i++;
    }
    return 1;
}

int dik_atoi(char *numb)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (numb[i] == '-' || numb[i] == '+')
    {
        if (numb[i] == '-')
            sign = -sign;
        i++;
    }
    while (numb[i] >= '0' && numb[i] <= '9')
    {
        result = result * 10 + (numb[i] - '0');
        i++;
    }
    return (result * sign);
}

void zmer_dputnbr(long int nb)
{
    char c;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        zmer_dputnbr(nb /10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

int calculatrice(long int hadik1, long int hadik2, char chno)
{
    long int wa_3yit;
    if (chno == '+')
        wa_3yit = hadik1 + hadik2;
    if (chno == '-')
        wa_3yit = hadik1 - hadik2;
    if (chno == '*')
        wa_3yit = hadik1 * hadik2;
    if (chno == '/')
        wa_3yit = hadik1 / hadik2;
    if (chno == '%')
        wa_3yit = hadik1 % hadik2;
    return (wa_3yit);
}

int l3adaw(char *lmrd)
{
    int i = 0;
    while (lmrd[i])
    {
        if (lmrd[i] >= '0' && lmrd[i] <= '9')
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    long int tfo;
    char nemra1[100];
    char nemra2[100];
    char op_sign = '0';

    if (argc != 2 || !lbaraje(argv[1]))
    {
        write(1, "\n", 1);
        return 0;
    }
    while (argv[1][i] == ' ' || argv[1][i] == '\t')
        i++;
    while (argv[1][i] && !(argv[1][i] == ' ' || argv[1][i] == '\t') && op_sign == '0')
    {
        if (argv[1][i] == '\0')
        {
            write(1, "\n", 1);
            return 0;
        }
        nemra1[j] = argv[1][i];
        j++;
        i++;
    }
    nemra1[j] = '\0';
    j = 0;
    
    while (argv[1][i] == ' ' || argv[1][i] == '\t')
        i++;
    
    if ((argv[1][i] == '-' || argv[1][i] == '+' 
        || argv[1][i] == '*' || argv[1][i] == '/' 
        || argv[1][i] == '%') && !(argv[1][i] >= '0' && argv[1][i] <= '9'))
    {
        op_sign = argv[1][i];
        i++;
    }

    if (!(op_sign == '/' || op_sign == '%' || op_sign == '-' || op_sign == '+' || op_sign == '*'))
    {
        write(1, "\n", 1);
        return 0;
    }

    if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
    {
        write(1, "\n", 1);
        return 0;
    }

    while (argv[1][i] == ' ' || argv[1][i] == '\t')
        i++;
    
    while (argv[1][i] && !(argv[1][i] == ' ' || argv[1][i] == '\t'))
    {
        if (argv[1][i] == '\0')
        {
            write(1, "\n", 1);
            return 0;
        }
        nemra2[j] = argv[1][i];
        j++;
        i++;
    }
    nemra2[j] = '\0';

    while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
        i++;
    
    if (argv[1][i] != '\0')
    {
        write(1, "\n", 1);
        return 0;
    }
    if (!lbaraje(nemra1))
    {
        write(1, "\n", 1);
        return 0;
    }
    if (!lbaraje(nemra2))
    {
        write(1, "\n", 1);
        return 0;
    }
    if (!l3adaw(nemra1) || !l3adaw(nemra2))
    {
        write(1, "\n", 1);
        return 0;
    }
    
    long int OGnemra1 = dik_atoi(nemra1);
    long int OGnemra2 = dik_atoi(nemra2);
    if ((op_sign == '/' || op_sign == '%') && OGnemra2 == 0)
    {
        write(1, "ERR\n", 4);
        return 0;
    }
    tfo = calculatrice(OGnemra1, OGnemra2, op_sign);
    zmer_dputnbr(tfo);
    write(1, "\n", 1);
    return 0;
}
