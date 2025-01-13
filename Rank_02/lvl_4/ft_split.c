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
