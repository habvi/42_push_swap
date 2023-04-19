#ifndef SOLVE_H
# define SOLVE_H

# define RECURSION_LIMIT	6

typedef struct s_data {
	t_nums	*stack_a;
	t_nums	*stack_b;
	int		*sorted_array;
	t_deque	*allocated_ptrs;
}	t_data;

// solve.c
void	solve(t_data data, t_error *error_code);

// solve_less_than_6/solve.c
void	solve_less_than_6(t_data data, t_error *error_code);

// solve_over_5/solve.c

#endif
