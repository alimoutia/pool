#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0;
    int j = 0;
    int word_printed = 0;
    while (argv[1][j])
        j++;
    j--;
    while (j >= 0)
    {
        while (j >= 0 && argv[1][j] != '\0' && (argv[1][j] == ' ' || argv[1][j] == '\t'))
            j--;
        if (j >= 0 && argv[1][j] != '\0' && argv[1][j] != ' ' && argv[1][j] != '\t')
        {
            while (j >= 0 && argv[1][j] != '\0' && argv[1][j] != ' ' && argv[1][j] != '\t')
                j--;
            i = j + 1;
            if (word_printed >= 1)
                write(1, " ", 1);
            while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            word_printed = 1;
        }
    }
    write(1, "\n", 1);
    return 0;
}
