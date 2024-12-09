/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:29:16 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/09 16:15:38 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Ne pas oublier le + 1 dans les vérifications 
// de start par rapport à end
// attention pour tester la fonction si on fait un while(str[i])
// et que start = 0 ca ne boucle pas,  
//faire while (i < len) avec len = longueur du tableau a testee

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int *tab;
	int i = 0;
	
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (0);
	if (start <= end)
	{
		while (i < len)
		{
			tab[i] = end - i;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < len)
		{
			tab[i] = end + i;
			i++;
		}
	}
	return (tab);
}

int main(void)
{
	int *tab = ft_rrange(0, -3);
	int len = 4;
	int i = 0;
	while (i < len)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}