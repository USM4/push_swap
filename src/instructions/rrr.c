/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:38:26 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 01:58:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_llist **stack_a, t_llist **stack_b, int flag)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (flag ==  1)
		write(1, "rrr\n", 4);
	else
		return ;
}
