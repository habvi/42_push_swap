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

typedef enum e_dir {
	NEXT = 0,
	PREV = 1
}	t_dir;

typedef struct s_block {
	t_deque	*wait_blocks;
	t_deque	*block_range;
}	t_block;

// --------------------------------------------
//  solve
// --------------------------------------------
// compress.c
t_nums	*compress_number(t_nums *nums, int *array);

// dup_num.c
t_nums	*dup_nums(t_nums *nums, t_error *error_code);

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

// --------------------------------------------
//  solve_le_6
// --------------------------------------------
// dfs.c
bool	is_operation_exceeded_answer_size(t_data *data);
bool	is_stack_a_sorted(t_nums *stack_a, t_nums *stack_b, int *sorted_array);
bool	is_limit_operation_size(size_t size);

// operations.c
bool	is_valid_operations(uint8_t op_i, t_data *data);

// solve.c
void	solve_le_6(t_data *data, t_error *error_code);

// update.c
void	update_answer(t_data *data, t_error *error_code);

// --------------------------------------------
//  solve_over_6
// --------------------------------------------
// solve.c
void	solve_over_6(t_data *data, t_error *error_code);

// sort_last.c
t_nums	*sort_from_large_num(t_deque *block, t_data *data, t_error *error_code);

// sort.c
t_nums	*divide_block_sort(t_data *data, t_error *erorr_code);

// stack_dfs.c
t_nums	*stack_dfs(t_block *block, t_data *data, t_error *error_code);

#endif
