/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:32:20 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/10 18:38:43 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_all(t_llist **stack_a, t_llist **stack_b)
{
    while(ft_lstsize((*stack_a)) != 5)
        (*stack_b) = push_to_stack(stack_a, *(stack_b));
    sort_five(stack_a, stack_b);
}

int  get_index(t_llist *stack, int a)
{
    int index;
    t_llist *current = stack;
    index = 0;
    
    while(current)
    {
        if (current->nbr == a)
            return(index);
       index++;
       current = current->next;
    }
    return (0);
}


int get_moves_to_top(t_llist *stack, int t)
{
    int index;
    int moves;
    
    moves = 0; 
    index = get_index(stack, t);
    if(index <= ft_lstsize(stack) / 2)
        moves = index;
    else if (index > ft_lstsize(stack)  / 2)
        moves = ft_lstsize(stack) - index;
    return(moves);
}

int	ll_min(t_llist	*head)
{
	int		min;
	int		tmp;
	t_llist	*iterator;

	iterator = head;
	min = iterator->nbr;
	iterator = iterator->next;
	while (iterator)
	{
        tmp = iterator->nbr;
		if (tmp < min)
			min = tmp;
		iterator = iterator->next;
	}
	return (min);
}

int get_upper_bound(t_llist *stack, int num)
{
    t_llist *sup;
    t_llist *iter;
    int     upper_bound;

    sup = NULL;
    iter = stack;
    while (iter)
    {
        if (iter->nbr > num)
            ft_lstadd_back(&sup, ft_lstnew(iter->nbr));
        iter = iter->next;
    }
    if (ft_lstsize(sup) == 0)
    {
        upper_bound = num;
        return (ft_lstclear(&sup), upper_bound);
    }
    upper_bound = ll_min(sup);
    return (ft_lstclear(&sup), upper_bound);
}
