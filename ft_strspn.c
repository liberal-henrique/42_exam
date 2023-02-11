#include <stdio.h>
#include <string.h>

//   The strspn() function spans the initial part of the null-terminated string
//s as long as the characters from s occur in the null-terminated string
//charset.  In other words, it computes the string array index of the first
//character of s which is not in charset, else the index of the first null
//character.

size_t  ft_strspn(const char *s, const char *charset)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s[i])
	{
		j = 0;
		flag = 0;
		while (charset[j])
		{
			if (charset[j] == s[i])

				flag = 1;
			j++;
		}
		if (flag == 0)
			break ;
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("My way:   %lu\n", ft_strspn("LuizHenrique Liberal de Souza", "HziuLebanrlq "));
	printf("Original: %lu\n", strspn("LuizHenrique Liberal de Souza", "HziuLebanrlq "));
}
