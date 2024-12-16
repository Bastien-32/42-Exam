/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:15:43 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/10 16:31:14 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char c;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int ft_atoi (char *s)
{
	int i = 0;
	int result = 0;
	
	while (s[i])
		result = result * 10 + s[i++] - '0';
	return (result);
}

void	tab_mut(char * s)
{
	int i = 1;
	int result; 

	while (i <= 9)
	{
		result = i * ft_atoi(s);
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(ft_atoi(s));
		write(1, " = ", 3);
		ft_putnbr(result);
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		tab_mut(av[1]);
	}
	write(1, "\n", 1);
}