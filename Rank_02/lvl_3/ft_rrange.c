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
	else
	{
		while (i < len)
		{
			tab[i] = end + i;
			i++;
		}
	}
	return (tab);
}
/* 
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
 */