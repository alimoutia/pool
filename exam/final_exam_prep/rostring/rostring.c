#include <unistd.h>

void ft_putstr_range(char *start, char *end)
{
    while (start < end)
    {
        write(1, start, 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        char *str = argv[1];
        int i = 0;

        // 1. Skip leading spaces/tabs
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        if (str[i])
        {
            // Save boundaries of the first word
            char *first_start = &str[i];
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
            char *first_end = &str[i];

            int word_printed = 0;

            // 2. Loop through remaining words
            while (str[i])
            {
                while (str[i] == ' ' || str[i] == '\t')
                    i++;
                if (str[i])
                {
                    if (word_printed)
                        write(1, " ", 1);
                    
                    char *word_start = &str[i];
                    while (str[i] && str[i] != ' ' && str[i] != '\t')
                        i++;
                    
                    ft_putstr_range(word_start, &str[i]);
                    word_printed = 1;
                }
            }

            // 3. Print space (if other words were printed) then print first word
            if (word_printed)
                write(1, " ", 1);
            ft_putstr_range(first_start, first_end);
        }
    }
    write(1, "\n", 1);
    return (0);
}