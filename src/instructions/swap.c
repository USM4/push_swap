#include "push_swap.h"

t_llist	*swap_first_e(t_llist *head, int flag)
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
    if(flag == 1)
        write(1,"sa\n",3);
    else
        write(1,"sb\n",3);
    return(head);
}