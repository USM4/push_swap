//stack B
//8, -1, 7, 9

typedef s_moves_holder {
    int nbr;
    int moves_at_a;
    int moves_at_b;
} t_moves_holder;

total_moves(arg) return (arg->moves_at_a + arg->moves_at_b);