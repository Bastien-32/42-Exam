/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:59:49 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/17 09:19:34 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	//if (!str)
	//	return (write(1, "(null)", 6));
	while (*str)
		i += write(1, str++, 1);
	return (i);
}

int ft_putnbr_pf(int nb)
{
	char	c;
	int		i;
	
	i = 0;
	if (nb == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (nb < 0)
	{
		nb *= -1;
		i += write(1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr_pf(nb / 10);
	c = (nb % 10) + '0';
	i += write(1, &c,1);
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_putnbr_base_pf(int nb, char *base)
{
	int		i;
	char	c;
	int		len;

	i = 0;
	len = ft_strlen(base);
	if (nb >= len)
		ft_putnbr_base_pf(nb / len, base);
	c = base[nb % len];
	i += write(1, &c, 1);
	return (i);
}

int ft_printf(const char *format, ...)
{
	int	i;
	va_list args;
	
	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				i += ft_putstr_pf(va_arg(args, char *));
			else if (*format == 'd')
				i += ft_putnbr_pf(va_arg(args, int));
			else if (*format == 'x')
				i += ft_putnbr_base_pf(va_arg(args, unsigned int), "0123456789abcdef");
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}

// int main(void)
// {
// 	ft_printf("%s\n%d\n%x", "un deux trois", 1, 22);
// }
