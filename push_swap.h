/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:27:44 by atrabut           #+#    #+#             */
/*   Updated: 2024/03/19 13:52:00 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

typedef struct s_objet
{
	int	index;
	int	mv_number;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	born1;
	int	born2;
}	t_objet;

//libft
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_putstr_fd(char *s, int fd);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

//parsing
int		checkrange(char **tab, int tabsize);
t_list	*crealist(char **argc, int argv);
t_list	*parsing(int *argc, char ***tab);
void	din(void *data);

//parsing2
int		checknumber(char *str);

//Split
void	frsplit(char **tab, int x);
int		countwords(char *str);
char	**split(char *str);

//Mouvements
void	reverse_rotate(t_list **pilea);
void	rotate(t_list **pilea);
void	push(t_list **pilea, t_list **pileb);
void	swap(t_list **pilea);
void	sortpile(t_list **pilea, t_list **pileb);
int		sizepile(t_list *list);
void	sortpile3(t_list **pilea);
void	rrotate_ab(t_list **pilea, t_list **pileb);
void	swapa(t_list **pilea);
void	swapb(t_list **pilea);
void	swapab(t_list **pilea, t_list **pileb);
void	pusha(t_list **pilea, t_list **pileb);
void	pushb(t_list **pilea, t_list **pileb);
void	rotate_a(t_list **pilea);
void	rotate_b(t_list **pilea);
void	rotate_ab(t_list **pilea, t_list **pileb);
void	rrotate_a(t_list **pilea);
void	rrotate_b(t_list **pilea);

//number_to_mv
t_objet	number_to_mv(t_list *pilea, t_list *pileb, t_objet *res);
int		mv_insert(t_list *pileb, int number);

//push_number
void	push_number(t_objet *res, t_list **pilea, t_list **pileb);

//utils
void	extractmax(t_list **pilea, int size);
void	extractmin(t_list **pilea, int size);
int		get_last_elemt(t_list *pile);
size_t	ft_strlen(const char *str);

//minmax
int		is_max(t_list *pile, int number);
int		is_min(t_list *pile, int number);
int		index_max(t_list *pilea);
int		index_min(t_list *pilea);

//Minisort
void	minisortb(t_list **pile);
void	minisorta(t_list **pile);
int		is_sort(t_list *pile);

#endif