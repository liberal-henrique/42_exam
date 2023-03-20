// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

#include <unistd.h>

int	give_index(char c)
{
	int index;

	index = 0;
	if (c >= 'A' && c <= 'Z')
		index = c - 'A';
	else if (c >= 'a' && c <= 'z')
		index = c - 'a';
	return (index);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	mult;
		int	i;

		i = 0;
		mult = 0;
		while (av[1][i])
		{
			mult = give_index(av[1][i]);
			while (mult-- >= 0)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
