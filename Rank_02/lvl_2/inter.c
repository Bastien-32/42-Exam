#include <unistd.h>
#include <stdlib.h>

int	char_in_str (char *str, char c)
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

void	inter(char *s1, char *s2)
{
	int		i;
	int		j;
	char	dest[256];

	i = 0;
	j = 0;
	while(s1[i])
	{
		if (!char_in_str(dest, s1[i]))
			dest[j++] = s1[i];
		i++;
	}
	dest[j] = '\0';
	j = 0;
	while (dest[j])
	{
		if (char_in_str(s2, dest[j]))
			write(1, &dest[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}