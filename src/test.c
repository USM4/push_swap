//stack B
//8, -1, 7, 9

typedef s_moves_holder {
    int nbr;
    int moves_at_a;
    int moves_at_b;
} t_moves_holder;

int main()
{
    t_moves_holder tmp;
    t_moves_holder best_move;

    best_move->nbr = fist_iteration->nbr;
    best_move->moves_at_a = moves_at_a(stack_a, stack->nbr);
    best_move->moves_at_b = moves_at_b(stack_b, stack->nbr);
    while (stuff there are numbers in stack B that we havent checked yet)
    {
        tmp->nbr = current_iteration->nbr;
        tmp->moves_at_a = moves_at_a(stack_a, current_iteration->nbr);
        tmp->moves_at_b = moves_at_b(stack_b, current_iteration->nbr);
        if (total_moves(tmp) < total_moves(best_move))
            best_move = tmp;
        increment the loop to the next element in
    }
    return (best_move);
}

total_moves(arg) return (arg->moves_at_a + arg->moves_at_b);