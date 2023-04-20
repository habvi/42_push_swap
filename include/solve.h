#ifndef SOLVE_H
# define SOLVE_H

# include <stdint.h>

# define RECURSION_LIMIT	6

typedef struct s_nums	t_nums;

typedef struct s_data {
	t_nums	*stack_a;
	t_nums	*stack_b;
	int		*sorted_array;
	t_deque	*allocated_ptrs;
	t_nums	*now_op;
	t_nums	*answer;
}	t_data;

// ----------------- solve------------------------
// init_set.c
t_nums	*init_and_set_pointer(\
			t_deque *allocated_ptrs, size_t init_num, t_error *error_code);

// put.c
void	print_operations(t_nums *answer, t_error *error_code);

// run.c
void	run_operation(uint8_t op_i, t_data *data, t_error *error_code);
void	undo_operation(uint8_t op_i, t_data *data, t_error *error_code);

// solve.c
void	solve(t_data *data, t_error *error_code);

// -------------- solve_less_than_6 --------------
// dfs.c
bool	is_operation_exceeded_answer_size(t_data *data);
bool	is_stack_a_sorted(t_nums *stack_a, t_nums *stack_b, int *sorted_array);
bool	is_limit_operation_size(size_t size);

// operations.c
bool	is_valid_operations(uint8_t op_i, t_data *data);

// solve.c
void	solve_less_than_6(t_data *data, t_error *error_code);

// update.c
void	update_answer(t_data *data, t_error *error_code);

// ---------------- solve_over_5 ----------------
// solve.c
void	solve_over_5(t_data *data, t_error *error_code);

#endif
