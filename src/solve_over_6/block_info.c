#include <stdint.h>
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

bool	is_num_in_range(int num, const int min, const int max)
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
	return (STACK_NONE);
}

t_block	*set_movable_stack_place(t_block *block, t_stack_place stack_place)
{
	uint8_t	i;
	int		count;

	i = 0;
	count = 1;
	while (count <= TOTAL_STACK_ENTRY)
	{
		if (count != (int)stack_place)
		{
			block->movable_stack_place[i] = count;
			i++;
		}
		count++;
	}
	return (block);
}

t_block	*set_block_info(\
		t_block *block, t_deque *block_range, t_data *data, t_error *error_code)
{
	block->stack_place = find_the_block_place(block_range, data);
	block = set_movable_stack_place(block, block->stack_place);
	block = set_nums_range_per_blocks(block, data, error_code);
	if (*error_code)
		return (NULL);
	return (block);
}
