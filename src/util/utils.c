/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:42:41 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/08 19:48:02 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int the_smallest(t_llist *head)
{
    t_llist *current;
    int smallest;

    smallest = head->nbr;
    current = head;

    while (current)
    {
        if (current->nbr < smallest)
            smallest = current->nbr;
        current = current->next;
    }
    
    return(smallest);
}

void check_is_clear_number(char **str)
{
	int i;
	
	i = 0;
	
	while (str[i])
	{
		if (ft_check_number(str[i]) == 1)
			i++;
		else
		{
			ft_putstr_fd("Wrong type form of number", 2);
			exit(1);
		}
	}
}