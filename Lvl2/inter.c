#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*base;
		char	*example;
		int		i;
		int		j;
		int		control;
		int		flag;

		base = av[1];
		example = av[2];
		i = 0;
		j = 0;
		while (base[j])
		{
			flag = 0;
			control = 0;
			i = 0;
			while (example[i])
			{	
				if (base[j] == example[i])
				{
					while (control < j)
					{
						if (base[j] == base[control])
							flag = 1;
						control++;
					}
					if (flag == 0)
						write (1, &base[j], 1);
					break ;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
