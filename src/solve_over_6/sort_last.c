#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static	bool	is_num_in_range(int num, const int min, const int max)
{
	if (min <= num && num <= max)
		return (true);
	return (false);
}

t_stack_place	find_the_block_place(t_deque *block_range, t_data *data)
{
	const t_deque	*stack_a = data->stack_a->deque;
	const t_deque	*stack_b = data->stack_b->deque;
	const int		min = block_range->first;
	const int		max = block_range->last;

	if (!deque_is_empty(stack_a))
	{
		if (is_num_in_range(stack_a->next->num, min, max))
			return (STACK_A_HEAD);
		if (is_num_in_range(stack_a->prev->num, min, max))
			return (STACK_A_TAIL);
	}
	if (!deque_is_empty(stack_b))
	{
		if (is_num_in_range(stack_b->next->num, min, max))
			return (STACK_B_HEAD);
		if (is_num_in_range(stack_b->prev->num, min, max))
			return (STACK_B_TAIL);
	}
	return (NONE);
}

// stack_place(1-4)
// STACK_A_HEAD --- stackA --- STACK_A_TAIL
// STACK_B_HEAD --- stackB --- STACK_B_TAIL
t_nums	*sort_last_num(t_deque *block_range, t_data *data, t_error *error_code)
{
	const t_stack_place	stack_place = find_the_block_place(block_range, data);

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
