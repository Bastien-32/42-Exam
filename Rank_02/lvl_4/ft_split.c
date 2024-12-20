#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

char    **ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	count;

	char	**tab = malloc(4096);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		count = 0;
		tab[j] = malloc(4096);
		if (! tab[j])
			return (NULL);
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


/*char    **ft_split(char *str)
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
}*/
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
		if ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			&& (i == 0 || str[i - 1] == ' ' || str[i] != '\t' || str[i] != '\n'))
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
			while (str[i + count] && str[i + count] != ' ' && str[i + count] != '\t' && str[i + count] != '\n')
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
 