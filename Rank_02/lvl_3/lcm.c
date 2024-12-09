/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:20:38 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 16:54:18 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int max;
	int result;
	
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
	result = a * b / max;
	return (result);
}

#include <stdio.h>

int main(void)
{
	int i = lcm(7, 9);
	printf("%d", i);
	return (0);
}