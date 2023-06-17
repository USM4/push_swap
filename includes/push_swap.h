/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:05:31 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 00:52:37 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "get_next_line.h"
# include <stdlib.h>

extern int	ft_strlen(const char *p);
extern void	ft_putchar_fd(char c, int fd);
extern void	ft_putnbr_fd(int n, int fd);
extern void	ft_putstr_fd(char *s, int fd);
extern char	**ft_split(char const *s, char c);
extern long	ft_atoi(char *str);
extern int	ft_isdigit(int a);
extern int	ft_check_number(char *num);

typedef struct s_llist{
	int				nbr;
	struct s_llist	*next;
}	t_llist;

typedef struct s_moves {
	int	nbr;
	int	moves_at_a;
	int	moves_at_b;
}	t_moves;

t_llist		*ft_lstlast(t_llist *lst);
t_llist		*ft_lstnew(int nbr);
t_moves		find_best_move(t_llist *stack_a, t_llist *stack_b);
extern int	ft_lstsize(t_llist *lst);
extern int	check_is_duplicated(t_llist *head);
extern int	the_smallest(t_llist *head);
extern int	get_index(t_llist *stack, int a);
extern int	check_is_sorted(t_llist *head);
extern int	ll_min(t_llist	*head);
extern int	get_upper_bound(t_llist *stack, int num);
extern int	get_moves_to_top(t_llist *stack, int nbr);
extern int	abs(int n);
extern void	ft_lstclear(t_llist **lst);
extern void	handling_parsing_errors(t_llist *stack_a);
extern void	ft_lstdelone(t_llist *lst);
extern void	ft_lstadd_back(t_llist **lst, t_llist *new);
extern void	swap_first_e(t_llist **head, int flag);
extern void	print_list(t_llist *head);
extern void	push_to_stack(t_llist **src, t_llist **dst, int flag);
extern void	ft_lstadd_front(t_llist **lst, t_llist *new);
extern void	rotate_stack(t_llist **head, int flag);
extern void	reverse_rotate(t_llist **head, int flag);
extern void	rr(t_llist **stack_a, t_llist **stack_b, int flag);
extern void	rrr(t_llist **stack_a, t_llist **stack_b, int flag);
extern void	check_is_clear_number(char **str);
extern void	create_llist(t_llist **stack, char **arr);
extern void	sort_three(t_llist **stack_a);
extern void	sort_four(t_llist **stack_a, t_llist **stack_b);
extern void	sort_five(t_llist **stack_a, t_llist **stack_b);
extern void	push_all(t_llist **stack_a, t_llist **stack_b);
extern void	ft_clean(char **arr);
extern void	execute(t_llist **stack_a, t_llist **stack_b, \
t_moves best_move);
extern void	rotate_to_top(t_llist **stack_x, int nbr, int flag);
extern void	parsing_numbers(t_llist **stack_a, int ac, char **av);
extern void	push_swap(t_llist **stack_a, t_llist **stack_b);
extern void ss(t_llist **stack_a, t_llist **stack_b);
 

#endif
