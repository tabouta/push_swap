/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:07:07 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:16:51 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_list **pilea)
{
	swap(pilea);
	ft_putstr_fd("sa\n", 1);
}

void	swapb(t_list **pilea)
{
	swap(pilea);
	ft_putstr_fd("sb\n", 1);
}

void	swapab(t_list **pilea, t_list **pileb)
{
	swap(pilea);
	swap(pileb);
	ft_putstr_fd("ss\n", 1);
}

void	pusha(t_list **pilea, t_list **pileb)
{
	push(pilea, pileb);
	ft_putstr_fd("pa\n", 1);
}

void	pushb(t_list **pilea, t_list **pileb)
{
	push(pileb, pilea);
	ft_putstr_fd("pb\n", 1);
}
