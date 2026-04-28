/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:20:43 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/27 19:16:15 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extractmax(t_list **pilea, int size)
{
	int	index;

	index = index_max(*pilea);
	if (index > size / 2)
	{
		while (index < size)
		{
			rrotate_b(pilea);
			index++;
		}
	}
	else
	{
		while (index)
		{
			rotate_b(pilea);
			index--;
		}
	}
}

void	extractmin(t_list **pilea, int size)
{
	int	index;

	index = index_min(*pilea);
	if (index > size / 2)
	{
		while (index < size)
		{
			rrotate_a(pilea);
			index++;
		}
	}
	else
	{
		while (index)
		{
			rotate_a(pilea);
			index--;
		}
	}
}

int	get_last_elemt(t_list *pile)
{
	if (!pile)
		return (ft_putstr_fd("get_last_element\n", 2), 0);
	while (pile->next)
		pile = pile->next;
	return (*(pile->content));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
