#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;

	if (!s)
		return (1);
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	if (!src)
		return (NULL);
	int length = ft_strlen(src);
	char *new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	int i = 0;

	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// int	main(void)
// {
// 	char s[] = "luiz Henrique";
// 	char *str;

// 	str = ft_strdup(s);
// 	printf("Test: %s\n", str);
// 	free(str);
// 	return (0);
// }
