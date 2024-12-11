#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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
			tab[j] = malloc(8);
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

int main(void)
{
	int i = 0;
	char *str = "Salut la Compagnie ! ";
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
	return (0);
}