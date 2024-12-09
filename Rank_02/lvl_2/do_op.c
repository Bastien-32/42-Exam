#include <unistd.h>

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return((int)result);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147463648)
	{
		write(1, "-2147463648", 12);
		return;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '*')
			ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
		if (argv[2][0] == '-')
			ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
		if (argv[2][0] == '+')
			ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
		if (argv[2][0] == '/')
			ft_putnbr(ft_atoi(argv[1]) / ft_atoi(argv[3]));
		if (argv[2][0] == '%')
			ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
	}
	write(1, "\n", 1);
	return (0);
}