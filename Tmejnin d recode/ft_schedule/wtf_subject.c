#include <unistd.h>

static int parse_time(char *s)
{
    int hours;
    int minutes;

    hours = (s[0] - '0') * 10 + (s[1] - '0');
    minutes = (s[3] - '0') * 10 + (s[4] - '0');
    return (hours * 60 + minutes);
}

static void print_time(int total_minutes)
{
    int hours;
    int minutes;
    char c;

    hours = total_minutes / 60;
    minutes = total_minutes % 60;

    c = (hours / 10) + '0';
    write(1, &c, 1);
    c = (hours % 10) + '0';
    write(1, &c, 1);

    write(1, ":", 1);

    c = (minutes / 10) + '0';
    write(1, &c, 1);
    c = (minutes % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int starts[1024];
    int ends[1024];
    int count;
    int i;
    int j;
    int cur_start;
    int cur_end;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    count = argc - 1;
    i = 0;

    while (i < count)
    {
        starts[i] = parse_time(argv[i + 1]);
        ends[i] = parse_time(argv[i + 1] + 6);
        i++;
    }

    i = 0;
    while (i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (starts[j] > starts[j + 1])
            {
                int tmp_start = starts[j];
                starts[j] = starts[j + 1];
                starts[j + 1] = tmp_start;

                int tmp_end = ends[j];
                ends[j] = ends[j + 1];
                ends[j + 1] = tmp_end;
            }
            j++;
        }
        i++;
    }

    cur_start = starts[0];
    cur_end = ends[0];
    i = 1;

    while (i < count)
    {
        if (starts[i] <= cur_end)
        {
            if (ends[i] > cur_end)
                cur_end = ends[i];
        }
        else
        {
            print_time(cur_start);
            write(1, "-", 1);
            print_time(cur_end);
            write(1, "\n", 1);
            cur_start = starts[i];
            cur_end = ends[i];
        }
        i++;
    }

    print_time(cur_start);
    write(1, "-", 1);
    print_time(cur_end);
    write(1, "\n", 1);

    return (0);
}