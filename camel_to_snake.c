// Assignment name  : camel_to_snake
// Expected files   : camel_to_snake.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// Examples:
// $>./camel_to_snake "hereIsACamelCaseWord"
// here_is_a_camel_case_word
// $>./camel_to_snake "helloWorld" | cat -e
// hello_world$
// $>./camel_to_snake | cat -e
// $

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*new_str;
		int		length;
		int		i;
		int		j;

		i = 0;
		j = 0;
		length = ft_strlen(av[1]);
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				j++;
			i++;
		}
		new_str = malloc(sizeof(char) * (length + j + 1));
		if (!new_str)
			return (0);
		j = 0;
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				new_str[j] = '_';
				j++;
				new_str[j] = av[1][i] + 32;
			}
			else
				new_str[j] = av[1][i];
			j++;
			i++;
		}
		i = 0;
		while (new_str[i])
		{
			write(1, &new_str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
