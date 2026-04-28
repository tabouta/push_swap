/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:51 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:04:05 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisortb(t_list **pile)
{
	int	sizepile;

	sizepile = ft_lstsize(*pile);
	if (sizepile <= 3)
	{
		if (*((*pile)->content) < *((*pile)->next->content))
		{
			if (*((*pile)->next->content) < get_last_elemt(*pile))
				swapb(pile);
			else if (*((*pile)->content) > get_last_elemt(*pile))
				swapb(pile);
		}
		else
		{
			if (*((*pile)->next->content) < get_last_elemt(*pile))
			{
				if (get_last_elemt(*pile) < *((*pile)->content))
					swapb(pile);
			}
		}
	}
}

void	minisorta(t_list **pile)
{
	int	sizepile;

	sizepile = ft_lstsize(*pile);
	if (sizepile <= 3)
	{
		if (*((*pile)->content) < *((*pile)->next->content))
		{
			if (*((*pile)->next->content) > get_last_elemt(*pile))
			{
				if (*((*pile)->content) < get_last_elemt(*pile))
					swapa(pile);
			}
		}
		else
		{
			if (*((*pile)->content) > *((*pile)->next->content))
			{
				if (get_last_elemt(*pile) > *((*pile)->content))
					swapa(pile);
				else if (*((*pile)->next->content) > get_last_elemt(*pile))
					swapa(pile);
			}
		}
	}
}

int	is_sort(t_list *pile)
{
	int	val;

	if (!pile)
		return (0);
	val = *(pile->content);
	while (pile)
	{
		if (val > *(pile->content))
			return (0);
		val = *(pile->content);
		pile = pile->next;
	}
	return (1);
}
