#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_count_words( char *str)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

int len_word( char *str, int begin)
{
	int i = 0;
	while (str[begin + i] != ' ' && str[begin + i])
	{
		i++;
	}
	return (i);
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int count;

	int word_count = ft_count_words(str);
	char **tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			tab[j] = malloc((len_word(str, i) + 1) * sizeof(char));
			if(!tab[j])
			{
                while (j > 0)
                    free(tab[--j]);
                free(tab);
                return NULL;
            }
			count = 0;
			while(str[i + count] != ' ' && str[i + count])
			{
				tab[j][count] = str[i + count];
				count ++;
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

void ft_putchar(char *str)
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
			ft_putchar(tab[i]);
			if ( i > 0)
				write(1, " ", 1);
			free(tab[i]);
			i--;
		}
		free(tab);
	}
	write(1, "\n", 1);
}