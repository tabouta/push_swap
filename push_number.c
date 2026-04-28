/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:41:16 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:06:39 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_pilea(t_objet *res, t_list *pile)
{
	int	size;

	size = ft_lstsize(pile);
	if (res->index > size / 2 + size % 2)
	{
		while (res->index < size)
		{
			res->rra++;
			size--;
		}
	}
	else
	{
		while (res->index)
		{
			res->index--;
			res->ra++;
		}
	}
}

static void	rotate_pileb(t_objet *res, t_list *pilea, t_list *pileb)
{
	int	i;
	int	pos;

	i = 0;
	while (i < res->index)
	{
		pilea = pilea->next;
		i++;
	}
	pos = mv_insert(pileb,*(pilea->content));
	if (pos > 0)
		res->rb += pos ;
	else
		res->rrb += -pos;
}

static void	simplify(t_objet *res)
{
	while (res->ra > 0 && res->rb > 0)
	{
		res->rr++;
		res->ra--;
		res->rb--;
	}
	while (res->rra > 0 && res->rrb > 0)
	{
		res->rrr++;
		res->rra--;
		res->rrb--;
	}
}

static void	follow_order(t_objet *res, t_list **pilea, t_list **pileb)
{
	while (res->ra--)
		rotate_a(pilea);
	while (res->rb--)
		rotate_b(pileb);
	while (res->rra--)
		rrotate_a(pilea);
	while (res->rrb--)
		rrotate_b(pileb);
	while (res->rr--)
		rotate_ab(pilea, pileb);
	while (res->rrr--)
		rrotate_ab(pilea, pileb);
}

void	push_number(t_objet *res, t_list **pilea, t_list **pileb)
{
	rotate_pileb(res, *pilea, *pileb);
	rotate_pilea(res, *pilea);
	simplify(res);
	follow_order(res, pilea, pileb);
	pushb(pilea, pileb);
}
// void push_number2(t_objet *res, t_list **pilea, t_list **pileb)
// {
// 	//printf("check\n");
// 	afflist(*pilea);
// 	afflist(*pileb);
// 	rotate_pileb(res, *pilea, *pileb);
// 	rotate_pilea(res, *pilea);
// 	//printf("check\n");
// 	affobjet(res);
// 	simplify(res);
// 	//printf("check\n");
// 	follow_order(res, pilea, pileb);
// 	pusha(pilea, pileb);
// }