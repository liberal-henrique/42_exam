#include <unistd.h>

void	ft_write_num(int num)
{
	char	str[] = "0123456789";

	if (num > 9)
		ft_write_num(num / 10);
	write(1, &str[num % 10], 1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == 13)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (write (1, "\n", 1));
	int	num;
	int	i;
	int	res;

	i = 1;
	res = 0;
	num = ft_atoi(av[1]);
	while (i <= 9)
	{
		ft_write_num(i);
		write(1, " x ", 3);
		ft_write_num(num);
		write(1, " = ", 3);
		res = 1 * num;
		ft_write_num(res);
		write(1, "\n", 3);
		i++;
	}
	return (0);
}
