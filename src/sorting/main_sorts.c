/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:46:12 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/09 17:30:38 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_llist **stack_a)
{
    if((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->next->next->nbr)
        (*stack_a) = reverse_rotate(&(*stack_a));
    else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr && (*stack_a)->nbr < (*stack_a)->next->next->nbr )
    {
        (*stack_a) = swap_first_e((*stack_a));
        (*stack_a) = rotate_stack(&(*stack_a));
    }
    else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
    {
        (*stack_a) = swap_first_e((*stack_a));
        (*stack_a) = reverse_rotate(&(*stack_a));
    }
    else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr && (*stack_a)->nbr < (*stack_a)->next->next->nbr)
        (*stack_a) = swap_first_e((*stack_a));
    else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
        (*stack_a) = rotate_stack(&(*stack_a));
}

void sort_four(t_llist **stack_a, t_llist **stack_b)
{
    if(the_smallest((*stack_a)) == (*stack_a)->nbr)
        (*stack_b) = push_to_stack(stack_a, (*stack_b));
    else
    {
        while((*stack_a)->nbr != the_smallest((*stack_a)))
            (*stack_a) = rotate_stack(stack_a);
        (*stack_b) = push_to_stack(stack_a, (*stack_b));
    }
    sort_three(stack_a);
    (*stack_a) = push_to_stack(stack_b, (*stack_a));
}

void    sort_five(t_llist **stack_a, t_llist **stack_b)
{
    if(the_smallest((*stack_a)) == (*stack_a)->nbr)
        (*stack_b) = push_to_stack(stack_a, (*stack_b));
    else
	{
		while((*stack_a)->nbr != the_smallest((*stack_a)))
           	(*stack_a) = rotate_stack(stack_a);
		(*stack_b) = push_to_stack(&(*stack_a), (*stack_b));
	}
	sort_four(stack_a, stack_b);
	(*stack_a) = push_to_stack(stack_b, (*stack_a));
}
