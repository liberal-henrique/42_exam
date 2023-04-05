
#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		int	flag = 0;

		while (ft_isspace(av[1][i]) == 1)
			i++;
		while (av[1][i])
		{
			while (ft_isspace(av[1][i]) == 1)
			{
				flag = 1;
				if (av[1][i + 1] == '\0')
					return (0);
				i++;
			}
			if (flag == 1)
			{
				flag = 0;
				write(1, "   ", 3);
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
