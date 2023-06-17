/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:08:10 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 01:26:40 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(t_llist *head)
// {
// 	while (head)
// 	{
// 		printf("%d", head->nbr);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// 	printf("\n");
// }


void	push_swap(t_llist **stack_a, t_llist **stack_b)
{
	if (ft_lstsize((*stack_a)) == 2)
		swap_first_e(stack_a, 1);
	else if (ft_lstsize((*stack_a)) == 3)
		sort_three(stack_a);
	else if (ft_lstsize((*stack_a)) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize((*stack_a)) == 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize((*stack_a)) > 5)
	{
		push_all(stack_a, stack_b);
		while ((*stack_b))
		{
			execute(stack_a, stack_b, \
			find_best_move((*stack_a), (*stack_b)));
		}
		rotate_to_top(stack_a, ll_min((*stack_a)), 1);
	}
}

int	main(int ac, char **av)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing_numbers(&stack_a, ac, av);
	handling_parsing_errors(stack_a);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
