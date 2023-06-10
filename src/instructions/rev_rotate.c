/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:14:44 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/06 13:53:10 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist *reverse_rotate(t_llist **head)
{
    t_llist *temp;
    t_llist *temp2;

    temp = *head;
    temp2 = ft_lstlast(*head);
    while (temp->next->next)
        temp = temp->next;
    temp->next = NULL;
    ft_lstadd_front(head,temp2);
    return((*head));
}