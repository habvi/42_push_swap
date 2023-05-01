#include "deque.h"
#include "push_swap.h"
#include "solve.h"

bool	is_in_range_for_sa(t_deque *block_range, t_data *data)
{
	if (!is_stack_head_num_in_range(block_range, data->stack_a->deque))
		return (true);
	if (!is_stack_next_num_in_range(block_range, data->stack_a->deque))
		return (true);
	return (false);
}

bool	is_in_range_for_sb(t_deque *block_range, t_data *data)
{
	if (!is_stack_head_num_in_range(block_range, data->stack_b->deque))
		return (true);
	if (!is_stack_next_num_in_range(block_range, data->stack_b->deque))
		return (true);
	return (false);
}

bool	is_in_range_for_ss(t_deque *block_range, t_data *data)
{
	if (is_executable_size(data->stack_a) && is_executable_size(data->stack_b))
	{
		if (is_in_range_for_sa(block_range, data))
			return (true);
		if (is_in_range_for_sb(block_range, data))
			return (true);
		return (false);
	}
	if (is_executable_size(data->stack_a))
		return (is_in_range_for_sa(block_range, data));
	if (is_executable_size(data->stack_b))
		return (is_in_range_for_sb(block_range, data));
	return (false);
}
