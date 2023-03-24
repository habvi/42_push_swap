#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

# include <stdio.h> // to do: erase

typedef struct s_nums {
	int		*list;
	size_t	size;
}	t_nums;

// parse.c
t_nums	parse_nums_from_argv(char *const *argv, bool *error);

// push_swap.c
void	push_swap(t_nums nums, bool *error);

#endif
