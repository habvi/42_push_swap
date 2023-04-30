#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	swap_head(t_deque *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque->next;
	swap_head(stack_a);
}

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

void	sb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque->next;
	swap_head(stack_b);
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
