#ifndef FREE_H
# define FREE_H

typedef struct s_nums	t_nums;

// free.c
void	free_strs(char **strs);
void	*free_nums(t_nums *nums);
void	free_array(int *array);

#endif
