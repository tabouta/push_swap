/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:11:41 by atrabut           #+#    #+#             */
/*   Updated: 2024/03/19 13:47:52 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = NULL;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
