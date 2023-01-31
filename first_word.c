// Assignment name  : first_word
// Expected files   : first_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its first word, followed by a
// newline.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

//"    luiz    henrique" --> "luiz"
//A -> 65 && Z --> 90 || a -> 97 && z -> 122

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
		while (*argv)
		{
			if (argv[1][i] == 32 || argv[1][i] == 9)
				i++;
			if ((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122))
			{
				while (argv[1][i] && argv[1][i] != 32 && argv[1][i] != 9)
				{
					c = argv[1][i];
					write(1, &c, 1);
					i++;
				}
				return (1);
			}
			i++;
		}
	}
}
