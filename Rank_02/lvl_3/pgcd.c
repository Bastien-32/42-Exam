/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:12 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/17 13:59:36 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int main (int ac, char **av)
{
	if (ac == 3)
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		int max;

		if (a > b)
			max = b;
		else
			max = a;
		while (max >= 1)
		{
			if (a % max == 0 && b % max == 0)
				break;
			else
				max--;
		}
		printf("%d", max);
	}
	printf("\n");
}