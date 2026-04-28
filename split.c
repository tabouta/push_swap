/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:57:54 by atrabut           #+#    #+#             */
/*   Updated: 2024/03/27 16:58:41 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	countwords(char *str)
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	res = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] != ' ' && flag)
		{
			res++;
			flag = 0;
		}
		else if (str[i] == ' ')
			flag = 1;
		i++;
	}
	return (res);
}

static int	sizeword(char *str, int i)
{
	int	res;

	res = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (res);
		res++;
		i++;
	}
	return (res);
}

void	frsplit(char **tab, int x)
{
	int	i;

	if (tab != NULL)
	{
		i = 1;
		while (i < x)
			free(tab[i++]);
		if (x)
			free(tab);
	}
}

static int	cpyword(char *dest, char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != ' ' && str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (j);
}

char	**split(char *str)
{
	char	**res;
	int		i;
	int		x;

	if (!countwords(str))
		return (NULL);
	res = (char **)malloc((countwords(str) + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	x = 1;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i])
		{	
			res[x] = (char *)malloc(sizeof(char) * (sizeword(str, i) + 1));
			if (!res[x])
				return (frsplit(res, x), NULL);
			i += cpyword(res[x++], str, i);
		}
	}
	res[x] = NULL;
	return (res);
}

// int main (int argc, char **argv)
// {
// 	// if (!argv[1][1])
// 	// 	printf("on va bien comprendre ......\n");
// 	if (argc <= 1)
// 		return (printf("pas assez d'arguments\n"),0);
// 	char **tab = split(argv[1]);
// 	int i = 1;
// 	while (tab[i])
// 	{
// 		printf("voici ma ligne numero %d =>%s<=\n",i + 1,tab[i]);
// 		i++;	
// 	}
// 	printf("sizetab res = %d\n",countwords(argv[1]));
// 	//frsplit(tab,sizetab(tab));
// 	return (0);
// }