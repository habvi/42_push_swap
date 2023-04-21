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
	t_nums	*lis_a;
	int		*copy_a;
}	t_data;

typedef enum e_dir {
	NEXT = 0,
	PREV = 1
}	t_dir;

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
//  solve_less_than_6
// --------------------------------------------
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

// --------------------------------------------
//  solve_over_5
// --------------------------------------------
// copy.c
int		*alloc_and_copy_stack_a(t_nums *stack_a, t_error *error_code);

// lis_reconstruct_find.c
size_t	find_lis_start_i(int *array_a, size_t size, const int lis_tail);
int		*find_insert_indexes(\
		t_data *data, t_nums *lis_a, const size_t start_i, t_error *error_code);

// lis_reconstruct.c
t_nums	*reconstruct_lis(t_data *data, t_nums *lis_a, t_error *error_code);

// lis.c
t_nums	*calc_stack_a_lis(t_data *data, t_error *error_code);

// pa.c
t_nums	*pushback_to_a_and_sort(t_data *data, t_error *error_code);

// pb_optimized.c
t_nums	*push_to_b_without_lis(t_data *data, t_error *error_code);

// solve.c
void	solve_over_5(t_data *data, t_error *error_code);

// update.c
void	update_lis_a(t_data *data, t_nums *new_lis_a, t_error *error_code);

#endif
