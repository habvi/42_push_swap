#ifndef CHECK_H
# define CHECK_H

# include <stdbool.h>

typedef struct s_nums	t_nums;
typedef enum e_error	t_error;

// check_sorted.c
bool	is_stack_a_already_sorted(t_nums *nums, int **array, t_error *error_code);

#endif
