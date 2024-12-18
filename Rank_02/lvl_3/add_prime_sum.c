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


void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	is_prime(int nb)
{
	int i = 2;
	while (i < nb)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	prime_sum(char *s1)
{
	int nb = ft_atoi(s1);
	int sum = 0;
	int	i = 2;
	
	while (i <= nb)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
} 

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		prime_sum(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
