/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:56:35 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:02:50 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//renvoie 1 si le nombre donner est plus grand que toute la pile donnee
int	is_max(t_list *pile, int number)
{
	while (pile)
	{
		if (number < *(pile->content))
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	is_min(t_list *pile, int number)
{
	while (pile)
	{
		if (number > *(pile->content))
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	index_min(t_list *pilea)
{
	int	val;
	int	res;
	int	index;

	res = 0;
	index = 1;
	if (!pilea)
		return (0);
	val = *(pilea->content);
	pilea = pilea->next;
	while (pilea)
	{
		if (val > *(pilea->content))
		{
			val = *(pilea->content);
			res = index;
		}
		index++;
		pilea = pilea->next;
	}
	return (res);
}

int	index_max(t_list *pilea)
{
	int	val;
	int	res;
	int	index;

	res = 0;
	index = 1;
	if (!pilea)
		return (0);
	val = *(pilea->content);
	pilea = pilea->next;
	while (pilea)
	{
		if (val < *(pilea->content))
		{
			val = *(pilea->content);
			res = index;
		}
		index++;
		pilea = pilea->next;
	}
	return (res);
}
