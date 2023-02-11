// Assignment name  : snake_to_camel
// Expected files   : snake_to_camel.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.

// A snake_case string is a string where each word is in lower case,
//  separated by an underscore "_".

// A lowerCamelCase string is a string where each word begins with a
//  capital letter except for the first one.

// Examples:
// $>./snake_to_camel "here_is_a_snake_case_word"
// hereIsASnakeCaseWord
// $>./snake_to_camel "hello_world" | cat -e
// helloWorld$
// $>./snake_to_camel | cat -e
// $

#include <stdlib.h>
#include <unistd.h>

void	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		count;
	int		index_new;
	int		flag;
	char	c;
	char	*new_str;

	i = 0;
	count = 0;
	flag = 0;
	index_new = 0;
	new_str = NULL;
	if (ac == 2)
	{	
		while (av[1][i] != '\0')
		{
			if (av[1][i] != '_')
				count++;	
			i++;
		}
		new_str = malloc(sizeof(char) * (count + 1));
		if (!new_str)
			return (0);
		i = 0;
		while (av[1][i])
		{
			flag = 0;
			if (av[1][i] == '_' )
			{
				i++;
				flag = 1;
				c = av[1][i];
				c = c - 32;
				new_str[index_new] = c;	
			}
			if (flag != 1)
			{
				c = av[1][i];
				new_str[index_new] = c;		
			}
			i++;
			index_new++;
		}
		putstr(new_str);
	}
	write(1, "\n", 1);
	return (0);
}

