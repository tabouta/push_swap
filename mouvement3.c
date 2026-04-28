/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:13:02 by atrabut           #+#    #+#             */
/*   Updated: 2024/01/22 20:17:16 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **pilea)
{
	rotate(pilea);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **pilea)
{
	rotate(pilea);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_list **pilea, t_list **pileb)
{
	rotate(pilea);
	rotate(pileb);
	ft_putstr_fd("rr\n", 1);
}

void	rrotate_a(t_list **pilea)
{
	reverse_rotate(pilea);
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_list **pilea)
{
	reverse_rotate(pilea);
	ft_putstr_fd("rrb\n", 1);
}
