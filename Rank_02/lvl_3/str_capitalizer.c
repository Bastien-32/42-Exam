#include <unistd.h>

void ft_str_capitalizer(char *s)
{
	int i = 0;
	
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (s[i] >= 'a' && s[i] <= 'z' &&
				(i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
	write( 1, "\n", 1);
}

int main(int ac, char **av)
{
	int i = 1;
	
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_str_capitalizer(av[i]);
			i++;
		}
	}
	else
		write( 1, "\n", 1);
}