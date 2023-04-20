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

void	sa(t_data *data, bool is_ss, t_run run, t_error *error_code)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque->next;
	swap_head(stack_a);
	if (is_ss)
		return ;
	if (run == RUN)
		append_now_op(data, SA, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	sb(t_data *data, bool is_ss, t_run run, t_error *error_code)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque->next;
	swap_head(stack_b);
	if (is_ss)
		return ;
	if (run == RUN)
		append_now_op(data, SB, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	ss(t_data *data, bool is_ss, t_run run, t_error *error_code)
{
	sa(data, is_ss, run, error_code);
	if (*error_code)
		return ;
	sb(data, is_ss, run, error_code);
	if (*error_code)
		return ;
	if (run == RUN)
		append_now_op(data, SS, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}
