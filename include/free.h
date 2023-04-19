#ifndef FREE_H
# define FREE_H

typedef struct s_deque	t_deque;
typedef struct s_nums	t_nums;
typedef enum e_type		t_type;

// free.c
void	free_strs(char **strs);
void	*free_nums(t_nums *nums);
void	free_array(int *array);
void	free_by_each_types(t_type type, void *ptr);
void	*free_all_pointers(t_deque *deque);

#endif
