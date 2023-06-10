/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:08:10 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/10 20:46:50 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_llist *head)
{
    while (head)
    {
        printf("%d", head->nbr);
        if (head->next)
            printf(" -> ");
        else
            printf("\n");
        head = head->next;
    }
}

int min_index(int *tab, int size)
{
    int i;
    i = 1;
    int min = 0;
    if (!size)
        return (NULL);
    while(i < size)
    {
        if(tab[i] < tab[min]) 
            min = i;
        i++;
    }
    return (min);
}


void   unit(t_llist *stack_a, t_llist *stack_b)
{
    t_llist *tempo;
    int *tab;
    tab = malloc(sizeof(int) * ft_lstsize(stack_b));
    int i = 0;
    int size = ft_lstsize(stack_b);
    tempo = stack_b;
    while(i < size)
    {
        tab[i]= get_moves_to_top(tempo, stack_b->nbr) + get_moves_to_top(stack_a, get_upper_bound(stack_a, stack_b->nbr));
        printf("stack content : %d  ",stack_b->nbr);
        printf("moves : %d\n   ",tab[i]);
        stack_b = stack_b->next;
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    t_llist *stack_a = NULL;
    // t_llist *stack_b = NULL;
    char **arr;

    i = 1;
    if (ac <= 1)
    {
        ft_putstr_fd("Wrong number of arguments", 2);
        exit(1);
    }

    while (i < ac)
    {
        arr = ft_split(av[i], ' ');
		check_is_clear_number(arr);
        stack_a = create_llist(stack_a, arr);
        i++;
    }

	if (ft_lstsize(stack_a) == 1)
	{
        ft_putstr_fd("One number is not enough\n", 2);
		exit(1);
	}

    if (check_is_sorted(stack_a) || check_is_duplicated(stack_a))
    {
        ft_putstr_fd("ALREADY SORTED OR DUPLICATED NUMBERS\n",2);
        exit(1);
    }
    // stack_a = swap_first_e(stack_a);
    // puts("THIRD PRINT");
    // stack_a = sort_three(stack_a);
    // if(ft_lstsize(stack_a) == 3)
    //     sort_three(&stack_a);
    // else if(ft_lstsize(stack_a) == 4)
    //     sort_four(&stack_a, &stack_b);
    // else if (ft_lstsize(stack_a) == 5)
    //     sort_five(&stack_a, &stack_b);
    // push_all(&stack_a, &stack_b);
    // print_list(stack_a);
    // print_list(stack_b);
    // unit(stack_a, stack_b);

    // print_list(stack_a);
    // int g = get_moves_to_top(stack_a, 188 );
    // printf("upper bound %d\n", g);

    int tab[5]={0,2,-8, 5, 8};
    printf("%d\n",min_index(tab, 5));
    
}