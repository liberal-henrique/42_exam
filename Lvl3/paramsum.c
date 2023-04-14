#include <unistd.h>

int write_num(int num)
{
    char str[] = "0123456789";

    if (num > 9)
        write_num(num / 10);
    return(write(1, &str[num % 10], 1));
}

int main (int ac, char **av)
{
    int i = 0;
    if (ac < 2)
    {
        write_num(i);
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (av[i + 1])
        i++;
    write_num(i);
    write(1, "\n", 1);
    return (0);
}
