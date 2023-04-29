#ifndef SOLVE_H
# define SOLVE_H

# include <stdint.h>

# define RECURSION_LIMIT		6
# define TOTAL_STACK_ENTRY		4
# define OTHER_STACK_NUMS_RANGE	7

// 3 or 4
# define LAST_BLOCK_SIZE		4
# define SWITCH_SOLUTION_NUMS	250
# define NUMS_SEPARATE_2		8
# define SEPARATE_2_BLOCKS		2
# define SEPARATE_3_BLOCKS		3

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

typedef enum e_stack_place {
	NONE = 0,
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
}	t_block;

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
void			run_operation(uint8_t op_i, t_data *data, t_error *error_code);
void			undo_operation(uint8_t op_i, t_data *data, t_error *error_code);

// solve.c
void			solve(t_data *data, t_error *error_code);

// --------------------------------------------
//  solve_le_6
// --------------------------------------------
// dfs.c
bool			is_operation_exceeded_answer_size(t_data *data);
bool			is_stack_a_sorted(\
				t_nums *stack_a, t_nums *stack_b, int *sorted_array);
bool			is_limit_operation_size(size_t size);

// operations.c
bool			is_valid_operations(uint8_t op_i, t_data *data);

// solve.c
void			solve_le_6(t_data *data, t_error *error_code);

// update.c
void			update_answer(t_data *data, t_error *error_code);

// --------------------------------------------
//  solve_over_6
// --------------------------------------------
// block_info.c
t_stack_place	find_the_block_place(t_deque *block_range, t_data *data);
t_block			*set_movable_stack_place(t_block *block, t_stack_place stack_place);
t_block			*set_block_info(t_block *block, t_deque *block_range, t_data *data, t_error *error_code);

// calc_block.c
t_block			*calc_base_block_size(\
					t_block *block, const unsigned block_range, t_data *data);

// divide.c
t_nums			*divide_nums_to_other_3_stacks(\
	t_block *block, t_deque *block_range, t_data *data, t_error *error_code);

// init.c
t_block			init_block(void);
t_deque			*deque_new_node_for_block(int first, int last, t_error *error);
t_deque			*allocate_deque_for_block(t_data *data, t_error *error_code);

// move.c
t_nums			*move_for_divide_nums(\
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
