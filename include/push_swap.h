#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

# define ERROR_MSG	"Error\n"

typedef enum e_status {
	SUCCESS = 0,
	ERROR = 1
}	t_status;

typedef struct s_nums {
	int		*list;
	size_t	size;
}	t_nums;

// args.c
bool	parse_nums_from_argv(char *const *argv, t_nums *nums);

// push_swap.c
bool	push_swap(const t_nums nums);

#endif
