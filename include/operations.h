#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdbool.h>

# define TOTAL_OPERATIONS	11
# define STR_SA				"sa"
# define STR_SB				"sb"
# define STR_SS				"ss"
# define STR_PA				"pa"
# define STR_PB				"pb"
# define STR_RA				"ra"
# define STR_RB				"rb"
# define STR_RR				"rr"
# define STR_RRA			"rra"
# define STR_RRB			"rrb"
# define STR_RRR			"rrr"

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
	UNDO = 2,
	RUN_TMP_OP = 3,
	UNDO_TMP_OP = 4
}	t_run;

// append_op.c
void	append_now_op(t_data *data, t_operation op, t_error *error_code);
void	append_op(t_nums *op_deque, t_operation op, t_error *error_code);

// pop_op.c
void	pop_now_op(t_nums *now_op);
void	pop_op(t_nums *op);

// push.c
void	pa(t_data *data);
void	run_pa(t_data *data, t_run run, t_error *error_code);
void	pb(t_data *data);
void	run_pb(t_data *data, t_run run, t_error *error_code);

// reverse_rotate_sub.c
void	rra(t_data *data);
void	rrb(t_data *data);

// reverse_rotate.c
void	run_rra(t_data *data, t_run run, t_error *error_code);
void	run_rrb(t_data *data, t_run run, t_error *error_code);
void	run_rrr(t_data *data, t_run run, t_error *error_code);

// rotate_sub.c
void	ra(t_data *data);
void	rb(t_data *data);

// rotate.c
void	run_ra(t_data *data, t_run run, t_error *error_code);
void	run_rb(t_data *data, t_run run, t_error *error_code);
void	run_rr(t_data *data, t_run run, t_error *error_code);

// swap_sub.c
void	sa(t_data *data);
void	sb(t_data *data);

// swap.c
void	run_sa(t_data *data, t_run run, t_error *error_code);
void	run_sb(t_data *data, t_run run, t_error *error_code);
void	run_ss(t_data *data, t_run run, t_error *error_code);

// test.c
void	test(t_nums *stack_a, t_nums *stack_b);

#endif
