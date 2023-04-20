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

void	rra(t_data *data, bool is_rrr, t_run run, t_error *error_code)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque;
	rotate_tail_to_head(stack_a);
	if (is_rrr)
		return ;
	if (run == RUN)
		append_now_op(data, RRA, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	rrb(t_data *data, bool is_rrr, t_run run, t_error *error_code)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque;
	rotate_tail_to_head(stack_b);
	if (is_rrr)
		return ;
	if (run == RUN)
		append_now_op(data, RRB, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	rrr(t_data *data, bool is_rrr, t_run run, t_error *error_code)
{
	rra(data, is_rrr, run, error_code);
	if (*error_code)
		return ;
	rrb(data, is_rrr, run, error_code);
	if (*error_code)
		return ;
	if (run == RUN)
		append_now_op(data, RRR, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}
