#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int count;

	char **tab = malloc(4096);
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			tab[j] = malloc(4096);
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
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char *str = av[1];
		char **tab = ft_split(str);

		if (!tab)
			return (1);
		while (tab[i])
		{
			printf("tab[%d] = %s\n", i, tab[i]);
			i++;
		}
		while (i > 0)
		{
			i--;
			free(tab[i]);
		}
		free(tab);
	}
	return (0);
}