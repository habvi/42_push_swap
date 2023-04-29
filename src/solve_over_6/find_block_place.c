#include "deque.h"
#include "error.h"
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
