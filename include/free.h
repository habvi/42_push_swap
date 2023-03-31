#ifndef FREE_H
# define FREE_H

typedef struct s_nums	t_nums;

// free.c
void	*free_nums(t_nums *nums);
void	free_array(int *array);
void	free_all(int *array, t_nums *nums);

#endif
