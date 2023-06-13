/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:42:53 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/13 00:34:46 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_stack(t_llist **src, t_llist **dst, int flag)
{
    t_llist *tmp;

    if(!(*src))
        return ;
    tmp = *src;
    (*src) = (*src)->next;
    ft_lstadd_front(dst, ft_lstnew(tmp->nbr));
    free(tmp);
    if(flag == 1)
        write(1,"pb\n",3);
    else
        write(1,"pa\n",3);  
}