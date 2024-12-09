/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:00:21 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 11:14:04 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	char_in_str(char *s, char c)
{
	int i = 0;
	while (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(4096);
	if (!dest)
		return;
	while (s1[i])
	{
		if (!char_in_str(dest, s1[i]))
		{
			dest[j] = s1[i];
			write(1, &dest[j], 1);
			j++;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!char_in_str(dest, s2[i]))
		{
			dest[j] = s2[i];
			write(1, &dest[j], 1);
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
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}