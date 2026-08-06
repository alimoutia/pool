#include <unistd.h>

int ft_atoi(char *nb)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if (nb[i] == '-' || nb[i] == '+')
    {
        sign = -sign;
        i++;
    }
    while (nb[i] >= '0' && nb[i] <= '9')
    {
        result = result * 10 + (nb[i] - '0');
        i++;
    }
    return (result * sign);
}

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        write(1, "Usage: ./ft_dice <1-6> [1-6] ...", 33);
        return 0;
    }
}