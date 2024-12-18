#include <unistd.h>

void	camel_to_snake(char *str)
{
	int	i = 0;
	char temp;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			temp = str[i];
			str[i] = '_';
			write(1, &str[i], 1);
			str[i] = temp + 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write (1, "\n", 1);
	return (0);
}