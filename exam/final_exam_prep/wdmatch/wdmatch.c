#include <unistd.h>

int checkword(char **argv)
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (argv[1][i])
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while (argv[2][i] != ' ' && )
        {

        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0;
    int j = 0;
    int word_printed = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == " " || argv[1][i] == "\t")
            word_printed = 1;
        while (argv[2][j])
        {
            if (argv[1][i] == argv[1][j])
                write(1, &argv[1][j], 1);
            if (word_printed == 1)
                write(1, " ", 1);
            j++;
        }
        i++;
    }
}
