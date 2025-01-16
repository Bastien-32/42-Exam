#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	result = 0;
	int		i = 0;

	while (str[i])
		result = result * 10 + str[i++] - '0';
	return(result);
}
#include <unistd.h>

int is_prime(int nb)
{
	int i = 2;
	while (i < nb)
	{
		if ( nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_putnbr(int nb)
{
	char *c;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void add_prime_sum( char *nbr)
{
	int nb = ft_atoi(nbr);
	int i = 2;
	int sum = 0;

	while (i <= nb)
	{
		if(is_prime(i))
			sum +=i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1] > 1)
		add_prime_sum(av[1]);
	else
		write(1, "0\n", 2);
	return (0);
}