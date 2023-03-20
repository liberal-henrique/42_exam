// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

//A -> 65 && Z --> 90 || a -> 97 && z -> 122

//"    ab c def  ghi  " --> ghi$

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	c;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (argv[1][i])
			i++;
		i--;
		while ((argv[1][i] == 32) || argv[1][i] >= 9 && argv[1][i] <= 13)
			i--;
		while ((argv[1][i] != 32) || (argv[1][i] <= 9 && argv[1][i] >= 13))
			i--;
		while (argv[1][i])
		{
			if (argv[1][i] != 32 || (argv[1][i] <= 9 && argv[1][i] >= 13))
			{
				c = argv[1][i];
				write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (1);
}
