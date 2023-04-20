#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h> // size_t

typedef struct s_deque	t_deque;
typedef struct s_nums	t_nums;
typedef enum e_error	t_error;

// copy.c
int		*copy_to_array_and_set(\
		t_nums *nums, t_deque *allocated_ptrs, t_error *error_code);

// print.c
void	print_array(int *array, size_t size, char *array_name);

// sort.c
void	sort_array(int *array, size_t size);

#endif
