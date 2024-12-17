#include <unistd.h>

int	ft_atoi(char *s)
{
	int i = 0;
	long result = 0;

	while (s[i] >= '0' && s[i] <= '9')
		result = result * 10 + s[i++] - '0';
	return ((int)result);
} 
void ft_putnbr_base(int nb, char *base)
{
	if (nb >= 16)
		ft_putnbr_base(nb / 16, base);
	write(1, &base[nb % 16], 1);
}

int	main(int argc, char **argv)
{
	char *base = "0123456789abcdef";
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) >= 0)
			ft_putnbr_base(ft_atoi(argv[1]), base);
	}
	write(1, "\n", 1);
	return (0);
} 

