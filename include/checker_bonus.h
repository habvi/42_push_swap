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

// checker.c
void		push_swap_checker(t_nums *stack_a, t_error *error_code);

// ft_strncmp.c
int			ft_strcmp(const char *s1, const char *s2);

// operation.c
t_operation	get_op_num(const char *op);
bool		is_valid_op(char *line, t_error *error_code);

// put.c
void		put_result(const char *result_message);

// sort.c
bool		is_stack_a_sorted_bonus(t_nums *stack_a);
void		move_op(t_nums *stack_a, t_nums *ops, t_error *error_code);

#endif
