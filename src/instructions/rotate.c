/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:48:16 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/06 13:42:28 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_llist *rotate_stack(t_llist **head)
{
    t_llist *temp;
    
    temp = *head;
    (*head) = (*head)->next;
    ft_lstadd_back(head,ft_lstnew(temp->nbr));
    free(temp);
    return(*head);
}