#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int count;

	char **tab = malloc(52);
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i - 1] == ' ' || i == 0))
		{
			tab[j] = malloc(word_in_str(str));
			if (!tab[j])
			{
				while (j > 0)
				{
					j--;
					free(tab[j]);
				}
				return (NULL);
			}
			count = 0;
			while (str[i + count] && str[i + count] != ' ')
			{
				tab[j][count] = str[i + count];
				count++;
			}
			tab[j][count] = '\0';
			j++;
			i += count;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
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