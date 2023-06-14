/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:08:10 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/14 02:53:35 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leaks(void)
{
    system("leaks push_swap");
}

void print_list(t_llist *head)
{
    while (head)
    {
        printf("%d", head->nbr);
        if (head->next)
            printf(" -> ");    
        head = head->next;
    }
    printf("\n");
}

int abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int total_moves(t_moves moves)
{
    int shared;

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


t_moves find_best_move(t_llist *stack_a, t_llist *stack_b)
{
    t_moves best_move;
    t_moves tmp;
    t_llist *iterator;
    
    best_move = (t_moves) { stack_b->nbr, get_moves_to_top(stack_a, get_upper_bound(stack_a, stack_b->nbr)), get_moves_to_top(stack_b, stack_b->nbr) };
    iterator = stack_b;
    while (iterator)
    {
        tmp = (t_moves) { iterator->nbr,  get_moves_to_top(stack_a, get_upper_bound(stack_a, iterator->nbr)), get_moves_to_top(stack_b, iterator->nbr) };
        if (total_moves(tmp) < total_moves(best_move))
            best_move = tmp;
        iterator = iterator->next;
    }
    return (best_move);
}

void execute_best_move(t_llist **stack_a, t_llist **stack_b, t_moves best_move)
{    
    while (best_move.moves_at_a > 0 && best_move.moves_at_b > 0)
    {
        best_move.moves_at_a--;
        best_move.moves_at_b--;
        rr(stack_a, stack_b);
    }
    while (best_move.moves_at_a < 0 && best_move.moves_at_b < 0)
    {
        best_move.moves_at_a++;
        best_move.moves_at_b++;
        rrr(stack_a, stack_b);
    }
    while (best_move.moves_at_a > 0)
    {
        best_move.moves_at_a--;
        rotate_stack(stack_a, 1);
    }
    while (best_move.moves_at_a < 0)
    {
        best_move.moves_at_a++;
        reverse_rotate(stack_a, 1);
    }
    while (best_move.moves_at_b > 0)
    {
        best_move.moves_at_b--;
        rotate_stack(stack_b, 2);
    }
    while (best_move.moves_at_b < 0)
    {
        best_move.moves_at_b++;
        reverse_rotate(stack_b, 2);
    }
    push_to_stack(stack_b, stack_a, 2);
}

void rotate_to_top(t_llist **stack_x, int nbr, int flag)
{
    int x = get_moves_to_top(*stack_x, nbr);
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
void	ft_clean(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int main(int ac, char **av)
{
    int i;
    t_llist *stack_a = NULL;
    // t_llist *stack_b = NULL;
    char **arr = NULL;

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
        create_llist(&stack_a, arr);
        i++;
    }
    print_list(stack_a);
	if (ft_lstsize(stack_a) == 1)
	{
        ft_putstr_fd("Error\nOne number is not enough\n", 2);
		exit(1);
	}

    if (check_is_sorted(stack_a))
    {
        ft_putstr_fd("Error\nALREADY SORTED\n",2);
        exit(1);
    }
    
    if( check_is_duplicated(stack_a))
    {
        ft_putstr_fd("Error\nDUPLICATED NUMBERS\n",2);
        exit(1);
    }
    
    if(ft_lstsize(stack_a) == 2)
        swap_first_e(&stack_a, 1);
    
    ft_clean(arr);
    ft_lstclear(&stack_a);
    // ft_lstclear(&stack_a);
    // ft_lstclear(&stack_a);
    // else if (ft_lstsize(stack_a) == 3)
    //     sort_three(&stack_a);
    // else if (ft_lstsize(stack_a) == 4)
    //     sort_four(&stack_a, &stack_b);
    // else if (ft_lstsize(stack_a) == 5)
    //     sort_five(&stack_a, &stack_b);
    // else if (ft_lstsize(stack_a) > 5)
    // {
    //     // while (ft_lstsize(stack_a) > 1)
    //     //     push_to_stack(&stack_a, &stack_b, 1);
    //     push_all(&stack_a, &stack_b);
    //     while (stack_b)
    //         execute_best_move(&stack_a, &stack_b, find_best_move(stack_a, stack_b));
    // rotate_to_top(&stack_a, ll_min(stack_a), 1);
    // }
    // stack_a = swap_first_e(stack_a);
    // puts("THIRD PRINT");
    // stack_a = sort_three(stack_a);
    // printf("stack a: ");
    // print_list(stack_a);
    // printf("stack b: ");
    // print_list(stack_b);
    // printf("\n\n");
    // printf("stack a: ");
    // print_list(stack_a);
    // printf("stack b: ");
    // print_list(stack_b);

    atexit(leaks);
}
