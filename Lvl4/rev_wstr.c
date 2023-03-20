// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in 
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the 
// begin/end of the string.

// If the number of parameters is different from 1, the program will display 
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional" 
// spaces (meaning that there won't be additionnal spaces at the beginning or at 
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

// "Wingardium Leviosa" | cat -e

#include <unistd.h>
#include <stdio.h>

int ft_isspace(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
		int	flag;
        int i;
        int j;

        i = 0;
        j = 0;
		flag = 0;
        while (av[1][i])
            i++;
		while (i >= 0)
		{
			i--;
			while (!ft_isspace(av[1][i]) && i)
				i--;
			if (ft_isspace(av[1][i]))
				j = i + 1;
			else
				j = i;
			while (!ft_isspace(av[1][j]) && av[1][j])
			{
				write(1, &av[1][j], 1);
				j++;
			}
			if (i != 0)
				write (1, " ", 1);
			i--;
		}
    }
    write (1, "\n", 1);
    return (0);
}


