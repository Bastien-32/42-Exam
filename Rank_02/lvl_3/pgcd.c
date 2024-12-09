/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:12 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 17:29:14 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    pgcd(unsigned int a, unsigned int b)
{
	int max;
	
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
	 	max = b;
	else 
		max = a;
	while (max >= 1)
	{
		if (a % max == 0 && b % max == 0)
			break;
		max--;
	}
	return (max);
}

#include <stdio.h>

int main(void)
{
	int i = pgcd(6, 9);
	printf("%d", i);
	return (0);
}