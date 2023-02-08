// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>
//"Que la      lumiere soit et la lumiere fut"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verify_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 32)
			return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int main (int argc, char **argv)
{
	int		i_first_word;
	int		i_general;
	char	*new_str;
	int		length;
	int		flag;


	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i_first_word = 0;
	length = 0;
	flag = 0;	{
	if (verify_str(argv[1]) == 0)
	{
		ft_putstr(argv[1]);
		return (0);
	}

	//deleting the spaces in the beginning of the string
	while (argv[1][i_first_word] == 32)
		argv[1]++;
	//discovering the length of the final string
	length = 0;
	i_general = 0;
	while (argv[1][i_general])
	{
		if ((argv[1][i_general] == 32) && flag == 0)
		{
			length++;
			flag = 1;
		}
		if (argv[1][i_general] != 32)
		{
			length++;
			flag = 0;
		}
		i_general++;
	}
	new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (0);

	//looking for the length of the first word
	while ((argv[1][i_first_word] != 32 || argv[1][i_first_word] >= 9 && argv[1][i_first_word] <= 13))
		i_first_word++;

	i_general = i_first_word;
	length = 0;
	flag = 0;
	while (argv[1][i_general] == 32)
		i_general++;
	while (argv[1][i_general])
	{
		if ((argv[1][i_general] == 32) && flag == 0)
		{
			new_str[length] = argv[1][i_general];
			length++;
			flag = 1;
		}
		if ((argv[1][i_general] != 32))
		{
			new_str[length] = argv[1][i_general];
			length++;
			flag = 0;
		}
		i_general++;
	}
	//To create space in case in strings finished with a letter
	if (new_str[length - 1] != 32)
		new_str[length++] = 32;
	//Copy the first word to the end of the new str;
	flag = 0;
	i_general = 0;
	while (argv[1][i_general] != 32)
	{
		if (argv[1][i_general] == 32)
			break ;
		new_str[length] = argv[1][i_general];
		length++;
		i_general++;
	}
	ft_putstr(new_str);
	return (0);
}


//--> eu ja consigo saber qual a dimensao da string final
//--> eu ainda nao consigo copiar o conteudo para a string final pois nao selecionei
//o conteudo limitando o numero de espacos. Portanto agr preciso copiar da segunda palavra
//em diante limitando os espacos em excesso.


// 	printf("%i\n", i_first_word);
// 	//know I can iterate through the whole string limiting the number of spaces
// 	//or tabs to just one between words.
// 	i_general = i_first_word;
// 	length = 0;
// 	while (argv[1][i_general])
// 	{
// 		new_str[length++] = argv[1][i_general];
// 		i_general++;
// 	}
// 	new_str[i_general] = '\0';
// 	printf("%s\n", new_str);
// 	return (0);
