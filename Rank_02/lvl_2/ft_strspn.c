#include <stdlib.h>

int	char_in_str (const char *str, const char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i = 0;
	
	while (s[i])
	{
		if (!char_in_str(accept, s[i]))
			return (i);
		i++;
	}
	return (i);
} 
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", (int)ft_strspn(argv[1], argv[2]));
	return (0);
}
*/
