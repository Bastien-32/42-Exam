/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:20:24 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/12 14:15:56 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;

		while (av[1][i])
			i++;
		int len = i;
		i = 0;
		while (av[1][len - 1] == ' ' || av[1][len - 1] == '\t')
			len--;
		while ((av[1][i] == ' ' || av[1][i] == '\t') && i < len)
			i++;
		while (i < len)
		{
			if (av[1][i] == ' ' && av[1][i + 1] == ' ')
				i++;
			else
			{
				if (av[1][i] == ' ')
					write(1, "  ", 2);
				write(1, &av[1][i++], 1);
			}
		}
	}
	write(1, "\n", 1);
}