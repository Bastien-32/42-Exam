#include <stdlib.h>
#include <stdio.h>

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