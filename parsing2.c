/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:56 by atrabut           #+#    #+#             */
/*   Updated: 2024/03/27 17:11:43 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strcmpmaxint(int neg, char *str, int index)
{
	int	i;

	i = 0;
	if (neg > 0)
	{
		while (str[index] && str[index] >= "2147483647"[i])
		{
			if (str[index++] > "2147483647"[i++])
				return (0);
		}
		return (1);
	}
	while (str[index] && str[index] >= "2147483647"[i])
	{
		if (str[index++] > "2147483648"[i++])
			return (0);
	}
	return (1);
}

int	checknumber(char *str)
{
	int		figurecount;
	int		i;
	int		neg;

	figurecount = ft_strlen(str);
	i = 0;
	neg = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			neg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	figurecount -= i;
	if (figurecount > 10 || ft_strlen(str) == 0)
		return (0);
	else if (figurecount == 10)
	{
		if (!strcmpmaxint(neg, str, i))
			return (0);
	}
	return (1);
}

void	din(void *data)
{
	free(data);
}

static void	*crealist_aux(t_list **temp, char **argc, int *i)
{
	(*temp)->next = (t_list *) malloc(sizeof(t_list));
	if (!(*temp)->next)
		return (ft_lstclear(temp, din), NULL);
	*temp = (*temp)->next;
	(*temp)->content = (int *) malloc (sizeof(int));
	if (!(*temp)->content)
		return (free(*temp), ft_lstclear(temp, din), NULL);
	*((*temp)->content) = atoi(argc[*i]);
	(*i) += 1;
	return (*temp);
}

t_list	*crealist(char **argc, int argv)
{
	t_list	*temp;
	t_list	*res;
	int		i;

	i = 2;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	res = temp;
	temp->content = (int *) malloc (sizeof(int));
	if (!temp->content)
		return (free(temp), NULL);
	*(temp->content) = atoi(argc[1]);
	while (i < argv)
	{
		if (!crealist_aux(&temp, argc, &i))
			return (NULL);
	}
	temp->next = NULL;
	return (res);
}
// t_list	*crealist(char **argc, int argv)
// {
// 	t_list	*temp;
// 	t_list	*res;
// 	int		i;

// 	i = 1;
// 	while (i < argv)
// 	{
// 		temp = (t_list *)malloc(sizeof(t_list));
// 		if (!temp)
// 			return (NULL);
// 		if (i == 1)
// 			res = temp;
// 		temp->content = (int *) malloc (sizeof(int));
// 		if (!temp->content)
// 			return (free(temp), ft_lstclear(&temp, din), NULL);
// 		*(temp->content) = atoi(argc[i++]);
// 		temp = temp->next;
// 	}
// 	return (res);
// }
