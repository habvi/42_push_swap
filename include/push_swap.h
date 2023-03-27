#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

# include <stdio.h> // to do: erase

typedef struct s_deque	t_deque;
typedef enum e_error	t_error;

typedef struct s_nums
{
	struct s_deque	*deque;
	size_t			size;
}	t_nums;

// exit.c
int		put_error(void);
void	*free_nums(t_nums *nums);
int		error_exit(t_nums *nums);

// nums.c
t_nums	*nums_new(t_error *error);
bool	is_valid_nums(t_nums *nums, t_error *error);

// parse.c
t_nums	*parse_nums_from_argv(char *const *argv, t_error *error);

// push_swap.c
void	push_swap(t_nums *nums, t_error *error);

#endif
