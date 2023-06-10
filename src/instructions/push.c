/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:42:53 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/06 13:56:34 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist *push_to_stack(t_llist **src, t_llist *dest)
{
    t_llist *temp;

    if(!(*src))
    {
        ft_putstr_fd("empty stack\n",2);
        exit(1);
    }
    temp = *src;
    (*src) = (*src)->next;
    ft_lstadd_front(&dest,ft_lstnew(temp->nbr));
    free(temp);
    return(dest);
}