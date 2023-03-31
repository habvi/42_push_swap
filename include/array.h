#ifndef ARRAY_H
# define ARRAY_H

typedef struct s_nums	t_nums;
typedef enum e_error	t_error;

// array_copy.c
int		*copy_to_array(t_nums *nums, t_error *error_code);

// array_sub.c
void	print_array(int *array, size_t size);
bool	free_array(int *array, bool ret);
void	free_all(int *array, t_nums *nums);

#endif
