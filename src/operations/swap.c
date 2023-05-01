#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	run_sa(t_data *data, t_run run, t_error *error_code)
{
	sa(data);
	if (run == RUN)
		append_op(data->now_op, SA, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, SA, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_sb(t_data *data, t_run run, t_error *error_code)
{
	sb(data);
	if (run == RUN)
		append_op(data->now_op, SB, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, SB, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}

void	run_ss(t_data *data, t_run run, t_error *error_code)
{
	sa(data);
	sb(data);
	if (run == RUN)
		append_op(data->now_op, SS, error_code);
	else if (run == UNDO)
		pop_op(data->now_op);
	else if (run == RUN_TMP_OP)
		append_op(data->tmp_op, SS, error_code);
	else if (run == UNDO_TMP_OP)
		pop_op(data->tmp_op);
}
