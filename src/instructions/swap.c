#include "push_swap.h"

t_llist	*swap_first_e(t_llist *head) 
{

    t_llist *first = head;
    t_llist *second = head->next;

    if(ft_lstsize(head) >= 2)
    {
        first->next = second->next;
        second->next = first;
        head = second;
    }
        // puts("SECOND PRINT");
        // print_list(head);
    return(head);
}