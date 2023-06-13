/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:34:22 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/13 01:46:14 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rr(t_llist **stack_a, t_llist **stack_b)
{
    rotate_stack(stack_a, 0);
    rotate_stack(stack_b, 0);
    write(1,"rr\n",3);

}