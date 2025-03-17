#include <stdlib.h>
#include <unistd.h>

char    **ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	count;

	char	**tab = (char **)malloc(sizeof(char *) * 4096);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		count = 0;
		tab[j] = malloc(sizeof(char) * 4096);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			tab[j][count++] = str[i++];
		tab[j][count] = '\0';
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

void ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char **tab = ft_split(av[1]);
		int i = 0;
		while(tab[i])
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(tab[i]);
			if ( i > 0)
				write(1, " ", 1);
			free(tab[i]);
			i--;
		}
		free(tab);
	}
	write(1, "\n", 1);
}