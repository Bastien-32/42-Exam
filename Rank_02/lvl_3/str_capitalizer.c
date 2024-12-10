/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:36:01 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/10 16:14:26 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_str_capitalizer(char *s)
{
	int i = 0;
	
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (s[i] >= 'a' && s[i] <= 'z' &&
				(s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\0'))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
	write( 1, "\n", 1);
}

int main(int ac, char **av)
{
	int i = 1;
	
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_str_capitalizer(av[i]);
			i++;
		}
	}
	else
		write( 1, "\n", 1);
}