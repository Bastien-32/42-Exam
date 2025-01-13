int	ft_atoi_base(const char *str, int str_base)
{
	int		i = 0;
	int		sign = 1;
	long	result = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			result = result * str_base + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result = result * str_base + str[i] - 'A' + 10;
		else
			break;
		i++;
	}
	result *= sign;
	return ((int)result);
}