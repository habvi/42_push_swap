#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// to do: erase
# include <stdio.h>

# define MAX_OP_LEN	4

typedef struct s_nums	t_nums;
typedef enum e_error	t_error;

typedef enum e_result {
	OK = 1,
	KO = 2
}	t_result;

// check.c
void		check_op(t_nums *stack_a, t_error *error_code);

// ft_strncmp.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// put.c
void		put_result(t_result result);

// sort.c
t_result	sort_and_judge(t_nums *stack_a, t_nums *op);

#endif
