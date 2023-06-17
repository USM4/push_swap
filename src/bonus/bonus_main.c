/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:49 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 19:57:19 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_checker(t_llist **stack_a, \
t_llist **stack_b, char *insruction)
{
	if (ft_strcmp(insruction, "sa\n") == 0)
		swap_first_e(stack_a, 0);
	else if (ft_strcmp(insruction, "sb\n") == 0)
		swap_first_e(stack_b, 0);
	else if (ft_strcmp(insruction, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(insruction, "ra\n") == 0)
		rotate_stack(stack_a, 0);
	else if (ft_strcmp(insruction, "rb\n") == 0)
		rotate_stack(stack_b, 0);
	else if (ft_strcmp(insruction, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(insruction, "rra\n") == 0)
		reverse_rotate(stack_a, 0);
	else if (ft_strcmp(insruction, "rrb\n") == 0)
		reverse_rotate(stack_b, 0);
	else if (ft_strcmp(insruction, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (ft_putstr_fd("Error\n", 2), exit(1));
}

int	main(int ac, char **av)
{
	t_llist	*stack_a;
	t_llist	*stack_b;
	char	*instructions;

	stack_a = NULL;
	stack_b = NULL;
	parsing_numbers(&stack_a, ac, av);
	handling_parsing_errors(stack_a);
	instructions = get_next_line(0);
	while (instructions)
	{
		instructions_checker(&stack_a, &stack_b, instructions);
		free(instructions);
		instructions = get_next_line(0);
	}
	if (check_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
