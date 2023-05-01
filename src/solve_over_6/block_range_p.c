#include "deque.h"
#include "push_swap.h"
#include "solve.h"

bool	is_in_range_for_pa(t_deque *block_range, t_data *data)
{
	return (!is_stack_head_num_in_range(block_range, data->stack_b->deque));
}

bool	is_in_range_for_pb(t_deque *block_range, t_data *data)
{
	return (!is_stack_head_num_in_range(block_range, data->stack_a->deque));
}
