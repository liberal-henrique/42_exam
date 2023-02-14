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

//"Luiz Henrique Liberal de Souza" --> "Souza de Liberal Henrique Luiz"

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			i++;
			if (av[1][i] == 32 || av[1][i] == 9 || av[1][i] == 11)
				flag = 1;
		}
		if (flag == 1)
			while (i >= 0)
			{
				if (av[1][i] == 32 || av[1][i] == 9 || av[1][i] == 11)
				{
					j = i;
					j++;
					while (av[1][j] != 32 && av[1][j] != 9 && av[1][j] != 11 && av[1][j] != '\0')
					{
						write(1, &av[1][j], 1);
						j++;	
					}
					write(1, " ", 1);
				}
				i--;
			}
		j = 0;
		while (av[1][j] != 32 && av[1][j] != 9 && av[1][j] != 11 && av[1][j] != '\0')
		{
			write(1, &av[1][j], 1);
			j++;	
		}
	}
	write(1, "\n", 1);
	return (0);
}

