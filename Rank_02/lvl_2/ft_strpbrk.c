#include <unistd.h>

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

char	*ft_strpbrk(const char *s, const char *reject)
{
	size_t	i;
	
	i = 0;
	while (s[i])
	{
		if(char_in_str(reject, s[i]))
			return(s + i);
		i++;
	}
	return (NULL);
} 
/* 
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%p", (char *)ft_strpbrk(argv[1], argv[2]));
	return (0);
}
 */
