/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:22:39 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/09 21:22:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_llist **lst)
{
	t_llist	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)-> next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
