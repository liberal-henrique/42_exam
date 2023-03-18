// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>
#include <stdio.h>

void    ft_write_hex(int num)
{
    char str[] = "0123456789abcdef";

    if (num > 15)
        ft_write_hex(num / 16);
    write(1, &str[num % 16], 1);
}

int ft_atoi(char *str)
{
    long int res;
    int sign;
    int i;

    i = 0;
    res = 0;
    sign = 1;
    if (!str)
        return (0);
    while (*str == 32 || *str == 9)
        str++;
    if (str[i] == '-')
    {
        sign = sign * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0';
        i++;
    }
    res = res * sign;
    if (res >  2147483647 || res < -2147483648)
        return (0);
    return (res);
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_write_hex(ft_atoi(av[1]));
    write (1, "\n", 1);
}
