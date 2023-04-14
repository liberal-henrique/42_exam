#include <stdlib.h>

int	counter(int start, int end)
{
	int	i = 0;
	if (start < end)
		while (start++ <= end)
			i++;
	else
		while (start-- >= end)
			i++;
	return (i);
}

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i;
	int length = counter(start, end);

	i = 0;
	arr = malloc(sizeof(int) * (length + 1));
	if (!arr)
		return (0);
	while (i < length)
	{
		if (start < end)
		{
			arr[i] = start;
			i++;
			start++;
		}
		else
		{
			arr[i] = start;
			i++;
			start--;
		}
	}
	return (arr);
}
