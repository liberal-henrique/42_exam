// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

//A -> 65 && Z --> 90 || a -> 97 && z -> 122
//"aaabcdefaghij" "bcdeffffywx" --> abcdefghijywx

//Terei de criar um ponteiro que olhe para trás
//da primeira string deve comparar apenas com ela mesma.

#include <unistd.h>

int	check_first_str(char *string, char element)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == element)
			return (1);
		index++;
	}
	return (0);
}

int	check_myself(char *string, int i)
{
	int	j;

	j = 0;
	while (j != i)
	{
		if (string[i] == string[j])
			return (1);
		j++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
    int i;
    int j;
    int index_first;
    int flag;
    char    c;

    i = 1;
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
    {
        //primeira letra sempre será impressa
        c = argv[1][0];
        write(1, &c, 1);
        //processo para análise da primeira string;
        while (argv[1][i])
        {
            flag = 0;
			flag = check_myself(argv[1], i);
            if (flag == 0)
            {
                c = argv[1][i];
                write(1, &c, 1);
            }
            i++;
        }
        //processo para análise da segunda string;
        i = 0;
        index_first = 0;
        while (argv[2][i])
        {
            flag = 0;
			if (i == 0)
			{
				flag = check_first_str(argv[1], argv[2][i]);
				if (flag == 0)
				{
					c = argv[2][i];
            		write(1, &c, 1);
				}
				i++;
			}
			flag = check_first_str(argv[1], argv[2][i]);
			if (flag != 1)
			{
				flag = check_myself(argv[2], i);
				if (flag == 0)
				{
					c = argv[2][i];
            		write(1, &c, 1);
				}
			}
            i++;
        }
        write(1, "\n", 1);
        return (1);
    }
}
