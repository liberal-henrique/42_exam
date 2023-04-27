#include <unistd.h>
#include <stdio.h>

int up(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int low(char c)
{
    return (c >= 'a' && c <= 'z');
}

int alp(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int space(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

//luiz henrique liberal de souza

char *put_low(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (up(s[i]))
            s[i] = s[i] + 32;
        i++;
    }
    return (s);
}

char *str_capitalizer(char *s)
{
    int i = 0;

    if (alp(s[i]))
        s[i] = s[i] - 32;
    while (s[i])
    {
        if (space(s[i]) && (low(s[i + 1]) == 1))
            s[i + 1] = s[i + 1] - 32;
        i++;
    }
    return (s);
}

int ft_strlen(char *s)
{
    int i = 0;

    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

void ft_put(char *s)
{
    write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
{
    int i = 1;
    char *c;
    char *result;
    if (ac < 2)
        return (write(1, "\n", 1));
    while (av[i])
    {
        c = put_low(av[i]);
        result = str_capitalizer(c);
        ft_put(result);
        write(1, "\n", 1);
        i++;
    }
    // write(1, "\n", 1);
    return (0);
}
