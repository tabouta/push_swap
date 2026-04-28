/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:43:55 by atrabut           #+#    #+#             */
/*   Updated: 2024/03/27 17:11:54 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkvar(char **tab, int argv)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	res = 1;
	if (tab == NULL)
		return (0);
	while (i < argv)
	{
		j = 0;
		if (j == 0 && (tab[i][j] == '+' || tab[i][j] == '-'))
		{
			j++;
			if (!tab[i][j])
				return (0);
		}
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j++] > '9')
				return (0);
		}
		i++;
	}
	return (res);
}

int	checkrange(char **tab, int tabsize)
{
	int	i;

	i = 1;
	while (i < tabsize)
	{
		if (!checknumber(tab[i++]))
			return (0);
	}
	return (1);
}

static int	checkdup(t_list *pile)
{
	int		i;
	t_list	*temp;

	while (pile)
	{
		temp = pile->next;
		i = *(pile->content);
		while (temp)
		{
			if (i == *(temp->content))
				return (0);
			temp = temp->next;
		}
		pile = pile->next;
	}
	return (1);
}

t_list	*parsing(int *argc, char ***tab)
{
	t_list	*pilea;
	int		flag;

	flag = 0;
	if (*argc <= 1)
		return (NULL);
	if (!checkvar(*tab, *argc))
	{
		flag = *argc;
		*argc = countwords((*tab)[1]) + 1;
		*tab = split((*tab)[1]);
		if (flag != 2 || !checkvar(*tab, *argc))
			return (frsplit(*tab, *argc), ft_putstr_fd("Error\n", 2), NULL);
		flag = 1;
	}
	if (!checkrange(*tab, *argc))
	{
		frsplit(*tab, (*argc) * flag);
		return (ft_putstr_fd("Error\n", 2), NULL);
	}
	pilea = crealist(*tab, *argc);
	frsplit(*tab, (*argc) * flag);
	if (!checkdup(pilea))
		return (ft_lstclear(&pilea, din), ft_putstr_fd("Error\n", 2), NULL);
	return (pilea);
}
