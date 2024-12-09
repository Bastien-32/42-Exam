#include <unistd.h>
/* #include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}
char *rev_print(char *str)
{
	int	i;
	int	len;
	char *dest;

	i = 0;
	len = ft_strlen(str);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[len - i - 1];
		i++;
	}
	dest[i] = '\0';
	ft_putstr(dest);
	write(1, "\n", 1);
	return (dest);
} */
#include <unistd.h>

char	*rev_print(char *str)
{
	int	i = 0;
	
	while(str[i])
		i++;
	while(--i >= 0)
		write(1, &str[i], 1);
	write(1, "\n", 1);
	return (str);
}

int main(void)
{
  rev_print("Hello world");
  write (1, "\n", 1);
  rev_print("tnirp esreveR");
  write (1, "\n", 1);
  rev_print("");
  write (1, "\n", 1);
}