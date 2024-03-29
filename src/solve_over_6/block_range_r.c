#include "deque.h"
#include "push_swap.h"
#include "solve.h"

bool	is_in_range_for_ra(t_deque *block_range, t_data *data)
{
	return (!is_stack_head_num_in_range(block_range, data->stack_a->deque));
}

bool	is_in_range_for_rb(t_deque *block_range, t_data *data)
{
	return (!is_stack_head_num_in_range(block_range, data->stack_b->deque));
}

bool	is_in_range_for_rr(t_deque *block_range, t_data *data)
{
	if (!deque_is_empty(data->stack_a->deque) \
		&& !deque_is_empty(data->stack_b->deque))
	{
		if (is_in_range_for_ra(block_range, data))
			return (true);
		if (is_in_range_for_rb(block_range, data))
			return (true);
		return (false);
	}
	if (!deque_is_empty(data->stack_a->deque))
		return (is_in_range_for_ra(block_range, data));
	if (!deque_is_empty(data->stack_b->deque))
		return (is_in_range_for_rb(block_range, data));
	return (false);
}
