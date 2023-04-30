#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdbool.h>

# define TOTAL_OPERATIONS		11
# define OPERATION_LIMIT_LE_6	11
# define TWO_OP					1
# define ONE_OP					0

typedef struct s_nums	t_nums;
typedef struct s_data	t_data;
typedef enum e_error	t_error;

typedef enum e_operation {
	OP_NONE = 0,
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11
}	t_operation;

typedef enum e_run {
	NONE = 0,
	RUN = 1,
	UNDO = 2
}	t_run;

// append_op.c
void	append_now_op(t_data *data, t_operation op, t_error *error_code);

// pop_op.c
void	pop_now_op(t_nums *now_op);

// push.c
void	pa(t_data *data, t_run run, t_error *error_code);
void	pb(t_data *data, t_run run, t_error *error_code);

// reverse_rotate.c
void	rra(t_data *data, bool is_rrr, t_run run, t_error *error_code);
void	rrb(t_data *data, bool is_rrr, t_run run, t_error *error_code);
void	rrr(t_data *data, bool is_rrr, t_run run, t_error *error_code);

// rotate.c
void	ra(t_data *data, bool is_rr, t_run run, t_error *error_code);
void	rb(t_data *data, bool is_rr, t_run run, t_error *error_code);
void	rr(t_data *data, bool is_rr, t_run run, t_error *error_code);

// swap.c
void	sa(t_data *data, bool is_ss, t_run run, t_error *error_code);
void	sb(t_data *data, bool is_ss, t_run run, t_error *error_code);
void	ss(t_data *data, bool is_ss, t_run run, t_error *error_code);

// test.c
void	test(t_nums *stack_a, t_nums *stack_b);

#endif
