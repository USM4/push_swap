/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:04:09 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 20:45:14 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_llist **stack_x, int nbr, int flag)
{
	int	x;

	x = get_moves_to_top(*stack_x, nbr);
	while (x > 0)
	{
		rotate_stack(stack_x, flag);
		x--;
	}
	while (x < 0)
	{
		reverse_rotate(stack_x, flag);
		x++;
	}
}

static int	total_moves(t_moves moves)
{
	int	shared;

	shared = 0;
	while (moves.moves_at_a > 0 && moves.moves_at_b > 0)
	{
		moves.moves_at_a--;
		moves.moves_at_b--;
		shared++;
	}
	while (moves.moves_at_a < 0 && moves.moves_at_b < 0)
	{
		moves.moves_at_a++;
		moves.moves_at_b++;
		shared++;
	}
	return (shared + abs(moves.moves_at_a) + abs(moves.moves_at_b));
}

t_moves	find_best_move(t_llist *stack_a, t_llist *stack_b)
{
	t_moves	best_move;
	t_moves	tmp;
	t_llist	*iterator;

	best_move = (t_moves){(stack_b->nbr), \
	get_moves_to_top(stack_a, get_upper_bound(stack_a, stack_b->nbr)), \
	get_moves_to_top(stack_b, stack_b->nbr)};
	iterator = stack_b;
	while (iterator)
	{
		tmp = (t_moves){iterator->nbr, \
		get_moves_to_top(stack_a, get_upper_bound(stack_a, iterator->nbr)), \
		get_moves_to_top(stack_b, iterator->nbr)};
		if (total_moves(tmp) < total_moves(best_move))
			best_move = tmp;
		iterator = iterator->next;
	}
	return (best_move);
}

void	rest_of_execution(t_llist **stack_a, t_llist **stack_b, t_moves move_at)
{
	while (move_at.moves_at_a > 0)
	{
		move_at.moves_at_a--;
		rotate_stack(stack_a, 1);
	}
	while (move_at.moves_at_a < 0)
	{
		move_at.moves_at_a++;
		reverse_rotate(stack_a, 1);
	}
	while (move_at.moves_at_b > 0)
	{
		move_at.moves_at_b--;
		rotate_stack(stack_b, 2);
	}
	while (move_at.moves_at_b < 0)
	{
		move_at.moves_at_b++;
		reverse_rotate(stack_b, 2);
	}
}

void	execute(t_llist **stack_a, t_llist **stack_b, t_moves best_move)
{
	while (best_move.moves_at_a > 0 && best_move.moves_at_b > 0)
	{
		best_move.moves_at_a--;
		best_move.moves_at_b--;
		rr(stack_a, stack_b, 1);
	}
	while (best_move.moves_at_a < 0 && best_move.moves_at_b < 0)
	{
		best_move.moves_at_a++;
		best_move.moves_at_b++;
		rrr(stack_a, stack_b, 1);
	}
	rest_of_execution(stack_a, stack_b, best_move);
	push_to_stack(stack_b, stack_a, 2);
}
