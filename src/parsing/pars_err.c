/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:55:57 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 02:20:02 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_numbers(t_llist **stack_a, int ac, char **av)
{
	int		i;
	char	**arr;

	arr = NULL;
	i = 1;
	if (ac <= 1)
	{
		ft_putstr_fd("Error\nWrong number of arguments", 2);
		exit(1);
	}
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		check_is_clear_number(arr);
		create_llist(stack_a, arr);
		ft_clean(arr);
		i++;
	}
}

void	handling_parsing_errors(t_llist *stack_a)
{
	if (ft_lstsize(stack_a) == 1)
	{
		ft_putstr_fd("Error\nOne number is not enough\n", 2);
		exit(1);
	}
	if (check_is_sorted(stack_a))
	{
		ft_putstr_fd("Error\nalready sorted\n", 2);
		exit(1);
	}
	if (check_is_duplicated(stack_a))
	{
		ft_putstr_fd("Error\nDUPLICATED NUMBERS\n", 2);
		exit(1);
	}
}
