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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

void	ft_wdmatch(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[i] && s1[j])
	{
		if (s1[j] == s2[i])
			j++;
		i++;
	}
	if (s1[j] == '\0')
		ft_putstr(s1);
	else
		return;
	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}