#include <unistd.h>

char *ft_strrev(char *str)
{
    int		len = 0;
    int		i = 0;
    char 	temp;

    if (!str)
        return (NULL);
    while (str[len])
        len++;
    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
    return (str);
}