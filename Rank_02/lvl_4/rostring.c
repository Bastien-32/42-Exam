#include <unistd.h>
#include <stdlib.h>

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

int word_in_str(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if(str[i] != ' ' && (str[i - 1] == ' ' || i == 0))
			count++;
		i++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 0;	
		char *str = av[1];
		int n = word_in_str(str) - 1;
		char **tab = ft_split(str);

		if (!tab)
			return (1);
		ft_putstr(tab[n]);
		write(1, " ", 1);
		n--;
		while (i <= n)
		{
			ft_putstr(tab[i]);
			if (i != n)
				write(1, " ", 1);
			i++;
		}
		i = word_in_str(str) - 1;
		while (i > 0)
		{
			i--;
			free(tab[i]);
		}
		free(tab);
	}
	write(1, "\n", 1);
	return (0);
}