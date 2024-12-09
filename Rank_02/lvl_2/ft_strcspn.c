/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:51:49 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/06 10:11:08 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

int	charset_in_str (char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	
	i = 0;
	while (s[i] && charset_in_str((char *)reject, s[i]))
		i++;
	return (i);
} */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (*s)
    {
        while (reject[i] && *s != reject[i])
            i++;
        if (reject[i] != '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", (int)ft_strcspn(argv[1], argv[2]));
	return (0);
}
