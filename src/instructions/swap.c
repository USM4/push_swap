#include "push_swap.h"

void    swap_first_e(t_llist **head, int flag)
{
    t_llist *first = (*head);
    t_llist *second = (*head)->next;

    first->next = second->next;
    second->next = first;
    (*head) = second;
    if(flag == 1)
        write(1,"sa\n",3);
    else
        write(1,"sb\n",3);
}