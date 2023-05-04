#ifndef SOLVE_H
# define SOLVE_H

# include "operations.h"

# define RECURSION_LIMIT				5
# define OPERATION_LIMIT_LESS_THAN_6	8

# define TOTAL_STACK_ENTRY		4
# define OTHER_STACK_NUMS_RANGE	7

# define LAST_BLOCK_SIZE		4
# define SWITCH_SOLUTION_NUMS	250
# define NUMS_SEPARATE_2		8
# define SEPARATE_2_BLOCKS		2
# define SEPARATE_3_BLOCKS		3

# define BLOCK_3				3
# define BLOCK_3_LIMIT			8
# define BLOCK_4				4
# define BLOCK_4_LIMIT			10

typedef struct s_nums	t_nums;
typedef enum e_run		t_run;

typedef struct s_data {
	t_nums	*stack_a;
	t_nums	*stack_b;
	int		*sorted_array;
	t_deque	*allocated_ptrs;
	t_nums	*now_op;
	t_nums	*answer;
	t_nums	*tmp_op;
	t_nums	*min_op;
}	t_data;

typedef enum e_dir {
	NEXT = 0,
	PREV = 1
}	t_dir;

typedef enum e_stack_place {
	STACK_NONE = 0,
	STACK_A_HEAD = 1,
	STACK_A_TAIL = 2,
	STACK_B_HEAD = 3,
	STACK_B_TAIL = 4
}	t_stack_place;

typedef struct s_block {
	t_deque			*wait_blocks;
	t_deque			*block_range;
	t_stack_place	stack_place;
	int				movable_stack_place[3];
	int				nums_range_per_blocks[7];
	unsigned int	base_block_size;
	unsigned int	total_block_count;
	int				each_block_range;
}	t_block;

typedef struct s_optimize {
	t_operation	before1;
	t_operation	before2;
	t_operation	after;
	t_operation	left;
	t_operation	right;
}	t_optimize;

// --------------------------------------------
//  solve
// --------------------------------------------
// compress.c
t_nums			*compress_number(t_nums *nums, int *array);

// dup_num.c
t_nums			*dup_nums(t_nums *nums, t_error *error_code);

// init_set.c
t_nums			*init_and_set_pointer(\
			t_deque *allocated_ptrs, size_t init_num, t_error *error_code);

// put.c
void			print_operations(t_nums *answer, t_error *error_code);

// run.c
void			run_operation(\
				t_operation op_i, t_data *data, t_run run, t_error *error_code);
void			undo_operation(\
				t_operation op_i, t_data *data, t_run run, t_error *error_code);

// solve.c
bool			is_stack_sorted(t_nums *stack, int *array);
bool			is_stack_a_sorted(\
				t_nums *stack_a, t_nums *stack_b, int *sorted_array);
void			solve(t_data *data, t_error *error_code);

// --------------------------------------------
//  solve_less_than_6
// --------------------------------------------
// operations.c
bool			is_executable_size(t_nums *nums);
bool			is_executable_operation(t_operation op_i, t_data *data);
bool			is_unnecessary_oparation(t_operation op_i, t_nums *op_deque);
bool			is_valid_operations(t_operation op_i, t_data *data);

// solve.c
void			solve_le_6(t_data *data, t_error *error_code);

// update.c
void			update_answer(t_data *data, t_error *error_code);
void			update_min_op(t_data *data, t_error *error_code);

// --------------------------------------------
//  solve_over_6
// --------------------------------------------
// block_info.c
bool			is_num_in_range(int num, const int min, const int max);
t_stack_place	find_the_block_place(t_deque *block_range, t_data *data);
t_block			*set_movable_stack_place(\
									t_block *block, t_stack_place stack_place);
t_block			*set_block_info(\
	t_block *block, t_deque *block_range, t_data *data, t_error *error_code);

// block_range_p.c
bool			is_in_range_for_pa(t_deque *block_range, t_data *data);
bool			is_in_range_for_pb(t_deque *block_range, t_data *data);

// block_range_r.c
bool			is_in_range_for_ra(t_deque *block_range, t_data *data);
bool			is_in_range_for_rb(t_deque *block_range, t_data *data);
bool			is_in_range_for_rr(t_deque *block_range, t_data *data);

// block_range_rr.c
bool			is_in_range_for_rra(t_deque *block_range, t_data *data);
bool			is_in_range_for_rrb(t_deque *block_range, t_data *data);
bool			is_in_range_for_rrr(t_deque *block_range, t_data *data);

// block_range_s.c
bool			is_in_range_for_sa(t_deque *block_range, t_data *data);
bool			is_in_range_for_sb(t_deque *block_range, t_data *data);
bool			is_in_range_for_ss(t_deque *block_range, t_data *data);

// block_range.c
bool			is_stack_head_num_in_range(\
										t_deque *block_range, t_deque *stack);
bool			is_stack_next_num_in_range(\
										t_deque *block_range, t_deque *stack);
bool			is_stack_tail_num_in_range(\
										t_deque *block_range, t_deque *stack);
bool			is_num_out_of_block_range(\
							t_operation op, t_deque *block_range, t_data *data);

// calc_block.c
t_block			*calc_base_block_size(\
					t_block *block, const unsigned block_range, t_data *data);

// dfs.c
t_nums			*last_nums_dfs(\
							t_block *block, t_data *data, t_error *error_code);

// divide.c
t_nums			*divide_nums_to_other_3_stacks(\
	t_block *block, t_deque *block_range, t_data *data, t_error *error_code);

// init.c
t_block			init_block(void);
t_deque			*deque_new_node_for_block(int first, int last, t_error *error);
t_deque			*allocate_deque_for_block(t_data *data, t_error *error_code);

// move_sub.c
t_nums			*move_from_stack_a_head(\
					const int after_place, t_data *data, t_error *error_code);
t_nums			*move_from_stack_a_tail(\
					const int after_place, t_data *data, t_error *error_code);
t_nums			*move_from_stack_b_head(\
					const int after_place, t_data *data, t_error *error_code);
t_nums			*move_from_stack_b_tail(\
					const int after_place, t_data *data, t_error *error_code);

// move.c
t_nums			*move_for_divide_nums(t_block *block, \
			const unsigned int nums_range, t_data *data, t_error *error_code);

// optimize_erase_adjacent.c
t_nums			*erase_adjacent_op(\
							t_nums *now_op, t_operation op1, t_operation op2);

// optimize_erase_pair.c
t_nums			*erase_pair_op(\
							t_nums *now_op, t_operation op1, t_operation op2);

// optimize_replace.c
t_nums			*replace_op(t_nums *now_op, t_operation before1, \
										t_operation before2, t_operation after);

// optimize.c
bool			is_separate_op(t_operation op);
bool			is_target_pair(\
		t_operation left, t_operation right, t_operation op1, t_operation op2);
t_nums			*optimize_op(t_nums *now_op);

// search.c
t_nums			*search_all_patterns(\
							t_block *block, t_data *data, t_error *error_code);

// set_range.c
t_block			*set_nums_range_per_blocks(\
						t_block *block, t_data *data, t_error *error_code);

// solve.c
t_nums			*divide_block_sort(t_data *data, t_error *erorr_code);
void			solve_over_6(t_data *data, t_error *error_code);

// sort_last.c
t_nums			*sort_last_num(\
				t_deque *block_range, t_data *data, t_error *error_code);

// stack_dfs.c
void			*free_block(t_deque	*block_range);
t_nums			*stack_dfs(t_block *block, t_data *data, t_error *error_code);

#endif
