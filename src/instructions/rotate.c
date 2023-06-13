/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:48:16 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/13 01:45:39 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    rotate_stack(t_llist **head, int flag)
{
    t_llist *temp;
    
    temp = *head;
    (*head) = (*head)->next;
    ft_lstadd_back(head,ft_lstnew(temp->nbr));
    free(temp);
    if(flag == 1)
        write(1,"ra\n",3);
    else if(flag == 2)
        write(1,"rb\n",3);
    else
        return;
}