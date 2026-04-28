/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:36 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:15:24 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_extreme(t_list *pile)
{
	int	i;
	int	previous ;
	int	size;

	size = ft_lstsize(pile);
	i = 0;
	previous = get_last_elemt(pile);
	while (pile)
	{
		if (is_max(pile, *(pile->content)) + is_min(pile, previous))
		{
			if (i > size / 2 + size % 2)
				return (i - size);
			return (i);
		}
		i++;
		previous = *(pile->content);
		pile = pile->next;
	}
	return (ft_putstr_fd("sortpile2 number_moove insert_b\n", 2), 0);
}

int	moovneed(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a <= 0 && b <= 0)
	{
		a = -a;
		b = -b;
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0)
		return (b - a);
	return (a - b);
}

t_objet	number_to_mv(t_list *pilea, t_list *pileb, t_objet *res)
{
	int	index;
	int	size;
	int	nmb_mv;
	int	a;

	index = 0;
	size = ft_lstsize(pilea);
	res->mv_number = moovneed(index, mv_insert(pileb, *(pilea->content)));
	while (pilea)
	{
		a = *(pilea->content);
		if (index < size / 2 + size % 2)
			nmb_mv = moovneed(index, mv_insert(pileb, a));
		else
			nmb_mv = moovneed(index - size, mv_insert(pileb, a));
		if (res->mv_number > nmb_mv)
		{
			res->mv_number = nmb_mv;
			res->index = index;
		}
		pilea = pilea->next;
		index++;
	}
	return (*res);
}

int	mv_insert(t_list *pileb, int number)
{
	int	i;
	int	pr;
	int	a;
	int	size;

	pr = get_last_elemt(pileb);
	size = ft_lstsize(pileb);
	i = 0;
	if (is_min(pileb, number) + is_max(pileb, number))
		return (is_extreme(pileb));
	while (pileb)
	{
		if (i == size / 2 + size % 2)
			i = i - size;
		a = *(pileb->content);
		if ((a < number && pr > number) || (a > number && pr < number))
		{
			if (is_max(pileb, a) + is_min(pileb, pr) != 2)
				return (i);
		}
		i++;
		pr = *(pileb->content);
		pileb = pileb->next;
	}
	return (ft_putstr_fd("number_to_moove mv_insert_b\n", 2), 0);
}
