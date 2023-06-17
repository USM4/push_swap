/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:14:44 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 02:01:56 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_llist **head, int flag)
{
    t_llist *temp;
    t_llist *temp2;

    temp = *head;
    temp2 = ft_lstlast(*head);
    while (temp->next->next)
        temp = temp->next;
    temp->next = NULL;
    ft_lstadd_front(head,temp2);
    if(flag == 1)
        write(1,"rra\n",4);
    if(flag == 2)
        write(1,"rrb\n",4);
    else
        return ;
}