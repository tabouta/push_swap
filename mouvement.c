/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:22:06 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:16:03 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **pilea)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*pilea) > 1)
	{
		temp = *pilea;
		*pilea = (*pilea)->next;
		temp2 = (*pilea)->next;
		(*pilea)->next = temp;
		(*pilea)->next->next = temp2;
	}
}

//empile l'element de la pile b sur la pile a
void	push(t_list **pilea, t_list **pileb)
{
	t_list	*temp;

	if ((*pileb))
	{
		temp = (*pileb)->next;
		(*pileb)->next = *pilea;
		(*pilea) = *pileb;
		*pileb = temp;
	}
	else
		ft_putstr_fd("appel de push avec une pile vide\n", 2);
}

void	rotate(t_list **pilea)
{
	t_list	*temp;

	if (*pilea)
	{
		temp = (*pilea)->next;
		ft_lstadd_back(pilea, *pilea);
		*pilea = temp;
	}
}

void	reverse_rotate(t_list **pilea)
{
	t_list	*temp;

	temp = *pilea;
	if (ft_lstsize(temp) > 1)
	{
		while (temp->next->next)
			temp = temp->next;
		ft_lstadd_front(pilea, temp->next);
		temp->next = NULL;
	}
}

void	rrotate_ab(t_list **pilea, t_list **pileb)
{
	reverse_rotate(pilea);
	reverse_rotate(pileb);
	ft_putstr_fd("rrr\n", 1);
}
