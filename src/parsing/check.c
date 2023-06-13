/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:11:26 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/13 21:16:58 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit (int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}

int ft_check_number(char *num)
{
    int i;

    i = 0;
    while (num[i])
    {   
        if((num[0] == '-' || num[0] == '+') && i == 0 && ft_isdigit(num[i + 1]))
            i++;
        else if(ft_isdigit(num[i]))
            i++;
        else
            return (0);
    }
    return (1);
}


int check_is_sorted(t_llist *head)
{
	t_llist *current;

	while(head)
	{
		if (head->next)
			current = head->next;
		while (current)
		{
			if (current->nbr < head->nbr)
			    return(0);
			current = current->next;
		}
		head = head->next;
	}
    return(1);
}

int check_is_duplicated(t_llist *head)
{
    t_llist *current = head;
    while(head)
    {
        if (head->next)
            current = head->next;
        while (current)
         {
            if (current->nbr == head->nbr)
                return(1);
            current = current->next;
        }
        head = head->next;
    }
    return(0);
}
 
 t_llist *create_llist(t_llist *head, char **arr)
{
    int i;
    
    i = 0;
    while (arr[i])
    {
		long x = ft_atoi(arr[i]);
		if (x < INT_MIN || x > INT_MAX)
		{
			ft_putstr_fd("MAX or MIN\n", 2);
			break;
		}
        ft_lstadd_back(&head ,ft_lstnew(x));
        i++;
    }
    return(head);
}
