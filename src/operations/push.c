#include <stdint.h>
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

void	pa(t_data *data, t_run run, t_error *error_code)
{
	t_nums	*stack_a;
	t_nums	*stack_b;
	t_deque	*move_node;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (deque_is_empty(stack_b->deque))
		return ;
	move_node = deque_pop_front(stack_b->deque);
	deque_add_front(stack_a->deque, move_node);
	stack_a->size += 1;
	stack_b->size -= 1;
	if (run == RUN)
		append_now_op(data, PA, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}

void	pb(t_data *data, t_run run, t_error *error_code)
{
	t_nums	*stack_a;
	t_nums	*stack_b;
	t_deque	*move_node;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (deque_is_empty(stack_a->deque))
		return ;
	move_node = deque_pop_front(stack_a->deque);
	deque_add_front(stack_b->deque, move_node);
	stack_a->size -= 1;
	stack_b->size += 1;
	if (run == RUN)
		append_now_op(data, PB, error_code);
	else if (run == UNDO)
		pop_now_op(data->now_op);
}
