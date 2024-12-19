/* Ne pas oublier de transformer le int n en long nbr pour que 
ça prenne en compte des nombres, au-delà de la limite de int */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int len(int nbr)
{
	int i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int i = len(nbr);
	char *str = (char *)malloc((i + 1) * sizeof(int));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		i--;
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
} 

int main (void)
{
	int i = 534;
	char *j = ft_itoa(i);
	printf("%s", j);
	free(j);
	return (0);
}