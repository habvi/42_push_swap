#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	run_ra(t_data *data, t_run run, t_error *error_code)
{
	ra(data);
	if (run == RUN)
		append_op(data->now_op, RA, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RA, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_rb(t_data *data, t_run run, t_error *error_code)
{
	rb(data);
	if (run == RUN)
		append_op(data->now_op, RB, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RB, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_rr(t_data *data, t_run run, t_error *error_code)
{
	ra(data);
	rb(data);
	if (run == RUN)
		append_op(data->now_op, RR, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RR, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}
