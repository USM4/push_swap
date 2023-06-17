/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:04:23 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 02:15:34 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_e(t_llist **head, int flag)
{
	t_llist	*first;
	t_llist	*second;

	first = (*head);
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	(*head) = second;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
	else
		return;
}
