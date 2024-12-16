/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:57:09 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/16 17:14:11 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* int	main(int ac, char **av)
{
	(void)av;
	
	printf("%d", (ac - 1));
	write(1, "\n", 1);
	return (0);
} */

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}