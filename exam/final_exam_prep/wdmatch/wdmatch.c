#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[2][j]) // Advance j through the second string
        {
            if (argv[1][i] == argv[2][j]) // If character matches, advance i in the first string
                i++;
            j++;
        }
        if (argv[1][i] == '\0') // If i reached the end of the first string, all characters were matched in order
        {
            i = 0;
            while (argv[1][i])
            {
                write(1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}
