// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdio.h>
#include <stdlib.h>

int	length_range(int limit, int item_to_decrement)
{
	int	i;
	int	count;

	i = item_to_decrement;
	count = 0;
	while (i-- >= limit)
		count++;
	return (count);
}

int     *ft_rrange(int start, int end)
{
	int *new_str;
	int	index;
	int	length;

	if (end < start)
		length = length_range(end, start);
	if (start < end)
		length = length_range(start, end);
	index = 0;
	new_str = malloc(sizeof(int) * (length + 1));
	if (!new_str)
		return (0);
	new_str[length] = '\0';
	if (end > start){
		while (end >= start)
			new_str[index++] = end--;
	}
	if (start > end)
	{
		while (end <= start)
			new_str[index++] = end++;
	}
	return (new_str);
}


int	main(void)
{
	int start = 10;
	int	end = -10;
	int length;
	int *new_str;

	printf("End: %i, start: %i\n", end, start);
	new_str = ft_rrange(start, end);
	length = 0;
	while (length < 21)
		printf("Number: %i, |", new_str[length++]);
	return (0);
}


