/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:59:31 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/02 18:52:55 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ft_lstnew(int nbr)
{
	t_llist	*newnode;

	newnode = malloc(sizeof(t_llist));
	if (!newnode)
		return (NULL);
	newnode->nbr = nbr;
	newnode->next = NULL;
	return (newnode);
}