/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:51:49 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/17 13:20:43 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	charset_in_str (char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	
	i = 0;
	while (s[i] && charset_in_str(reject, s[i]))
		i++;
	return (i);
} 
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", (int)ft_strcspn(argv[1], argv[2]));
	return (0);
}
*/
