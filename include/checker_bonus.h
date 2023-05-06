#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdbool.h>
# include <stddef.h>

# define SAME_STRING	0

# define OK_MSG			"OK\n"
# define KO_MSG			"KO\n"

typedef struct s_deque		t_deque;
typedef struct s_nums		t_nums;
typedef enum e_error		t_error;
typedef enum e_operation	t_operation;

typedef enum e_result {
	RESULT_OK = 1,
	RESULT_KO = 2,
	RESULT_ERROR = 3
}	t_result;

// check_operations.c
void		check_operations(\
						t_nums *stack_a, int *sorted_a, t_error *error_code);

// ft_strncmp.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// operation.c
bool		is_valid_op(const char *line);
t_operation	get_op_index(const char *op);

// put.c
void		put_result(t_result result);

// sort.c
t_result	sort_and_judge(\
			t_nums *stack_a, t_nums *ops, int *sorted_a, t_error *error_code);

#endif
