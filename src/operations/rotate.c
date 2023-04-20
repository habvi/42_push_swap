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

void	ra(t_data *data, bool is_rr, t_run run, t_error *error_code)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_head_to_tail(stack_a);
	if (is_rr)
		return ;
	if (run == RUN)
		append_now_op(data, RA, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	rb(t_data *data, bool is_rr, t_run run, t_error *error_code)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_head_to_tail(stack_b);
	if (is_rr)
		return ;
	if (run == RUN)
		append_now_op(data, RB, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	rr(t_data *data, bool is_rr, t_run run, t_error *error_code)
{
	ra(data, is_rr, run, error_code);
	if (*error_code)
		return ;
	rb(data, is_rr, run, error_code);
	if (*error_code)
		return ;
	if (run == RUN)
		append_now_op(data, RR, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}
