#include <unistd.h>
#include <stdio.h>

int	up(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	alp(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
// "a FiRSt LiTTlE TESt" -> A firsT littlE tesT$
int	main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1));
	int i = 1;
	int j = 0;
	char c;

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((low(av[i][j]) == 1) && ((space(av[i][j + 1]) == 1) || (av[i][j + 1] == '\0')))
			{
				c = av[i][j] - 32;
				write(1, &c, 1);
			}
			else if ((up(av[i][j]) == 1) && ((space(av[i][j + 1]) == 1) || (av[i][j + 1] == '\0')))
			{
				c = av[i][j];
				write(1, &c, 1);
			}
			else if ((up(av[i][j]) == 1) && (space(av[i][j + 1]) == 0))
			{
				c = av[i][j] + 32;
				write(1, &c, 1);
			}
			else
				write(1, &av[i][j], 1);
			j++; 
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%i\n", alp('.'));
// }
