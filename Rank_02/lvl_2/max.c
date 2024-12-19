#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int i = 1;
	int temp;
	
	if (!len || !tab)
		return (0);
	if (len == 1)
		return (tab[0]);
	while (i < (int)len)
	{
		if (tab[0] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[0];
			tab[0] = temp;
		}
		i++;
	}
	return (tab[0]);
}

/*
int main(void)
{ 
	int tab[6] = {1, 8, 5, 3, 9, 18};
	int i = max(tab, 6);
	printf("%d", i);
	return (0);
}
*/