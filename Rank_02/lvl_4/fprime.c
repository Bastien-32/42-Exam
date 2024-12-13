/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:36:23 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/13 16:30:54 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Ne pas oublier les conditions pour 0 et 1
Bien retenir De diviser le nombre par le nombre premier trouvé et 
la condition d'affichage de "*" Juste après cette opération */

#include <stdio.h>
#include <stdlib.h>

void fprime(char *s)
{
	int nb = atoi(s);
	int i = 2;
	
	if (nb == 1)
		printf("1");
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			nb /= i;
			if (nb != 1)
				printf("*");
			i = 2;
		}
		i++;
	}
	
	 
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(av[1]);
	}
	printf("\n");
}