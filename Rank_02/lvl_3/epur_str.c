/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:20:24 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 13:05:02 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int	main(int argc, char **av)
{
	int i = 0;
	int len = (int)ft_strlen(av[1]) - 1;
	
	if (argc == 2)
	{
		while ((av[1][len - i] == ' ' || av[1][len - i] == '\t')
				&& av[1][len - i])
			i++;
		int end = len - i + 1;
		i = 0;
		while ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i] < end)
			i++;
		while (i < end)
		{
			if ((av[1][i] == ' ' || av[1][i] == '\t') &&
					(av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
				i++;
			else
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
}