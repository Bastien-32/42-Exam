/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:03:13 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 10:59:22 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i = 0;
	
	while(s[i])
		i++;
	return (i);
}

void	inter(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return;
	while(s1[i])
	{
		if (!char_in_str(dest, s1[i]))
			dest[j++] = s1[i];
		i++;
	}
	dest[j] = '\0';
	i = 0;
	j = 0;
	while (s2[i] && dest[j])
	{
		if (s2[i] == dest[j])
		{
			write(1, &s2[i], 1);
			j++;
		}
		i++;
	}
	free(dest);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}