/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:04:23 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/16 13:39:15 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !*begin_list)
		return;

	t_list	*current = *begin_list;
	t_list	*previous = NULL;
	
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (!previous)
			{
				*begin_list = current->next;
				free(current);
				current = *begin_list;
			}
			else
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
			}
		}
		else 
		{
			previous = current;
			current = current->next;
		}
	}
}