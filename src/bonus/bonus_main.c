/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:49 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 01:01:34 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void instructions_checker(t_llist **stack_a , t_llist **stack_b, char *insruction)
{
	if(ft_strncmp(insruction,"sa\n",3) == 0)
		swap_first_e(stack_a, 0);    
	else if(ft_strncmp(insruction,"sb\n",3) == 0)
		swap_first_e(stack_b, 0);
	else if(ft_strncmp(insruction,"ss\n",3) == 0)
		ss(stack_a, stack_b);
	else if(ft_strncmp(insruction,"ra\n",3) == 0)
		rotate_stack(stack_a, 0);
	else if(ft_strncmp(insruction,"rb\n",3) == 0)
		rotate_stack(stack_b, 0);
	else if(ft_strncmp(insruction,"rr\n",3) == 0)
		rr(stack_a, stack_b, 0);
	else if(ft_strncmp(insruction,"rra\n",4) == 0)
		reverse_rotate(stack_a, 0);        
	else if(ft_strncmp(insruction,"rrb\n",4) == 0)
		reverse_rotate(stack_b, 0);
    else if(ft_strncmp(insruction,"rrr\n",4) == 0)
        rrr(stack_a, stack_b, 0);
}
int	main(int ac, char **av)
{
	t_llist	*stack_a;
	t_llist	*stack_b;
    char *instructions;

	stack_a = NULL;
	stack_b = NULL;
	parsing_numbers(&stack_a, ac, av);
    handling_parsing_errors(stack_a);

    instructions = get_next_line(0);
    while(instructions)
    {   
        instructions_checker(&stack_a, &stack_b, instructions);
        instructions = get_next_line(0);
    }
    // check is sorted or not
	if(check_is_sorted(stack_a))
		write(1,"OK\n",3);
	else
		write(1,"KO\n",3);
}
