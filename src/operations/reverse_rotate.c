#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	rotate_tail_to_head(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_back(stack);
	deque_add_front(stack, move_node);
}

void	rra(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_tail_to_head(stack_a);
}

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

void	rrb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_tail_to_head(stack_b);
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
