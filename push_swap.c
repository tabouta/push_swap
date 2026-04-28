/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:14:16 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 19:57:55 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initobjet(t_objet *res)
{
	res->index = 0;
	res->mv_number = 0;
	res->ra = 0;
	res->rb = 0;
	res->rra = 0;
	res->rrb = 0;
	res->rr = 0;
	res->rrr = 0;
}

static void	initpileb(t_list **pileb, t_list **pilea, int size)
{
	if (size < 0)
		extractmin(pilea, ft_lstsize(*pilea));
	else if (size == 0)
	{
		minisorta(pilea);
		extractmin(pilea, ft_lstsize(*pilea));
	}
	else if (size <= 7)
	{
		while (0 < size--)
			pushb(pilea, pileb);
		minisorta(pilea);
	}
	else
	{
		pushb(pilea, pileb);
		pushb(pilea, pileb);
		pushb(pilea, pileb);
		minisortb(pileb);
	}
}

void	sortshort(t_list **pilea, t_list **pileb)
{
	int	tempb;
	int	tempa;

	while (*pileb)
	{
		tempb = *((*pileb)->content);
		tempa = *((*pilea)->content);
		if (is_min(*pilea, tempb) || is_max(*pilea, tempb))
		{
			if (is_min(*pilea, tempa))
				pusha(pilea, pileb);
			else
				rotate_a(pilea);
		}
		else if (tempb < tempa && tempb > get_last_elemt(*pilea))
			pusha(pilea, pileb);
		else
			rotate_a(pilea);
	}
}

int	main_aux(t_list **pilea, t_list **pileb)
{
	int		i;
	t_objet	res;

	i = ft_lstsize(*pilea) - 3;
	initpileb(pileb, pilea, i);
	if (i <= 7)
	{
		if (i > 0)
		{
			sortshort(pilea, pileb);
			extractmin(pilea, ft_lstsize(*pilea));
		}
		return (0);
	}
	else
	{
		while (i)
		{
			initobjet(&res);
			number_to_mv(*pilea, *pileb, &res);
			push_number(&res, pilea, pileb);
			i--;
		}
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pilea;
	t_list	*pileb;
	int		i;

	pilea = parsing(&argc, &argv);
	if (!pilea)
		return (0);
	pileb = NULL;
	if (is_sort(pilea))
		return (ft_lstclear(&pilea, din), ft_lstclear(&pileb, din), 0);
	if (main_aux(&pilea, &pileb))
	{
		extractmax(&pileb, ft_lstsize(pileb));
		i = ft_lstsize(pileb);
		while (i--)
			pusha(&pilea, &pileb);
	}
	return (ft_lstclear(&pilea, din), ft_lstclear(&pileb, din), 0);
}
