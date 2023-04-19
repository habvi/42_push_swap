#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_deque	t_deque;
typedef enum e_error	t_error;

typedef struct s_nums {
	struct s_deque	*deque;
	size_t			size;
}	t_nums;

typedef enum e_type {
	POINTER	= 1,
	T_DEQUE	= 2,
	T_NUMS = 3
}	t_type;

// check_nums.c
bool	is_valid_stack_nums(\
	t_nums *stack, int **array, t_deque *allocated_ptrs, t_error *error_code);

// compress.c
t_nums	*compress_number(t_nums *nums, int *array);

// nums_new.c
t_nums	*nums_new(t_error *error_code);
t_nums	*init_nums(t_error *error_code);

// parse.c
t_nums	*parse_nums_from_argv(char *const *argv, t_error *error);

// push_swap.c
void	set_allocated_pointer(\
		t_deque *allocated_ptrs, t_type type, void *ptr, t_error *error_code);
void	*push_swap(t_nums *stack_a, t_error *error_code);

#endif
