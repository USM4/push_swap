/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:34:22 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 01:55:06 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_llist **stack_a, t_llist **stack_b, int flag)
{
	rotate_stack(stack_a, 0);
	rotate_stack(stack_b, 0);
	if(flag == 1)
		write(1, "rr\n", 3);
	else
		return ;
}
