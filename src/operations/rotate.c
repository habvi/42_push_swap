#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	rotate_head_to_tail(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_front(stack);
	deque_add_back(stack, move_node);
}

void	ra(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_head_to_tail(stack_a);
}

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

void	rb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_head_to_tail(stack_b);
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
