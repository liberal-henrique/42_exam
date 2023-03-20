// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		printf("Meu: %i\n", ft_strcmp(av[1], av[2]));
// 		printf("Deles: %i", strcmp(av[1], av[2]));
// 	}
// 	printf("\n");
// 	return (0);
// }
