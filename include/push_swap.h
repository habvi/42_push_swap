#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_deque	t_deque;
typedef enum e_error	t_error;

typedef struct s_nums
{
	struct s_deque	*deque;
	size_t			size;
}	t_nums;

// check_nums.c
bool	is_valid_nums(t_nums *nums, int **sorted_array, t_error *error_code);

// compress.c
t_nums	*compress_number(t_nums *nums, int *array);

// nums_new.c
t_nums	*nums_new(t_error *error_code);
t_nums	*init_nums(t_error *error_code);

// parse.c
t_nums	*parse_nums_from_argv(char *const *argv, t_error *error);

// push_swap.c
void	push_swap(t_nums *nums, t_error *error_code);

#endif
