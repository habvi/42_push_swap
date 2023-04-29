#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static t_stack_place	find_the_block_place(t_deque *block, t_data *data)
{
	const t_deque	*stack_a = data->stack_a->deque;
	const t_deque	*stack_b = data->stack_b->deque;
	const int		min = block->first;
	const int		max = block->last;
	int				num;

	if (!deque_is_empty(stack_a))
	{
		num = stack_a->next->num;
		if (min <= num && num <= max)
			return (STACK_A_HEAD);
		num = stack_a->prev->num;
		if (min <= num && num <= max)
			return (STACK_A_TAIL);
	}
	if (!deque_is_empty(stack_b))
	{
		num = stack_b->next->num;
		if (min <= num && num <= max)
			return (STACK_B_HEAD);
		num = stack_b->prev->num;
		if (min <= num && num <= max)
			return (STACK_B_TAIL);
	}
	return (NONE);
}

// stack_place(1-4)
// STACK_A_HEAD --- stackA --- STACK_A_TAIL
// STACK_B_HEAD --- stackB --- STACK_B_TAIL
t_nums	*sort_from_large_num(t_deque *block, t_data *data, t_error *error_code)
{
	const t_stack_place	stack_place = find_the_block_place(block, data);

	if (stack_place == STACK_A_HEAD)
		return (data->now_op);
	else if (stack_place == STACK_A_TAIL)
		rra(data, false, RUN, error_code);
	else if (stack_place == STACK_B_HEAD)
		pa(data, RUN, error_code);
	else if (stack_place == STACK_B_TAIL)
	{
		rrb(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pa(data, RUN, error_code);
	}
	if (*error_code)
		return (NULL);
	return (data->now_op);
}
