#include <unistd.h>
#include <stdio.h>

int space(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

int low(char c)
{
    return ((c >= 'a' && c <= 'z') );
}

int up(char c)
{
    return ((c >= 'A' && c <= 'Z'));
}

int main(int ac, char **av)
{
    int     i;
    char    c;
    char    str[] = "zyxwvutsrqponmlkjihgfedcba";
    char    s[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            c = av[1][i];
            if (up(c))
                c = s[c - 'A'];
            if (low(c))
                c = str[c - 'a'];
            write(1, &c, 1);
            i++;
        }

    }
    write(1, "\n", 1);
    return (0);
}
