#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	run_rra(t_data *data, t_run run, t_error *error_code)
{
	rra(data);
	if (run == RUN)
		append_op(data->now_op, RRA, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RRA, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_rrb(t_data *data, t_run run, t_error *error_code)
{
	rrb(data);
	if (run == RUN)
		append_op(data->now_op, RRB, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RRB, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_rrr(t_data *data, t_run run, t_error *error_code)
{
	rra(data);
	rrb(data);
	if (run == RUN)
		append_op(data->now_op, RRR, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, RRR, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}
