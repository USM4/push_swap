/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:46:12 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 02:07:56 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_llist **stack_a)
{
	if ((*stack_a)->nbr < (*stack_a)->next->nbr && \
	(*stack_a)->nbr > (*stack_a)->next->next->nbr)
		reverse_rotate(stack_a, 1);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr && \
	(*stack_a)->next->nbr > (*stack_a)->next->next->nbr && \
	(*stack_a)->nbr < (*stack_a)->next->next->nbr)
	{
		swap_first_e(stack_a, 1);
		rotate_stack(stack_a, 1);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && \
	(*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
	{
		swap_first_e(stack_a, 1);
		reverse_rotate(stack_a, 1);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && \
	(*stack_a)->next->nbr < (*stack_a)->next->next->nbr && \
	(*stack_a)->nbr < (*stack_a)->next->next->nbr)
		swap_first_e(stack_a, 1);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && \
	(*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
		rotate_stack(stack_a, 1);
}

void	sort_four(t_llist **stack_a, t_llist **stack_b)
{
	if (the_smallest((*stack_a)) == (*stack_a)->nbr)
		push_to_stack(stack_a, stack_b, 1);
	else
	{
		while ((*stack_a)->nbr != the_smallest((*stack_a)))
			rotate_stack(stack_a, 1);
		push_to_stack(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	push_to_stack(stack_b, stack_a, 2);
}

void	sort_five(t_llist **stack_a, t_llist **stack_b)
{
	if (the_smallest((*stack_a)) == (*stack_a)->nbr)
		push_to_stack(stack_a, stack_b, 1);
	else
	{
		while ((*stack_a)->nbr != the_smallest((*stack_a)))
			rotate_stack(stack_a, 1);
		push_to_stack(stack_a, stack_b, 1);
	}
	sort_four(stack_a, stack_b);
	push_to_stack(stack_b, stack_a, 2);
}
