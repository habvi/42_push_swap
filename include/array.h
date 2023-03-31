#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h> // size_t

typedef struct s_nums	t_nums;
typedef enum e_error	t_error;

// array_print.c
void	print_array(int *array, size_t size, char *array_name);

// array.c
int		*copy_to_array(t_nums *nums, t_error *error_code);

#endif