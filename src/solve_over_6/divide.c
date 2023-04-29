#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static t_block	*set_movable_stack_place(\
								t_block *block, t_stack_place stack_place)
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

static t_deque	*set_nums_range_per_blocks(t_block *block, t_data *data)
{
	(void)data;
	return (block->nums_range_per_blocks);
}

static t_nums	*move_for_divide_nums(t_block *block, t_data *data, t_error *error_code)
{
	(void)block;
	(void)error_code;
	return (data->now_op);
}

t_nums	*divide_nums_to_other_3_stacks(\
		t_block *block, t_deque *block_range, t_data *data, t_error *error_code)
{
	const t_stack_place	stack_place = find_the_block_place(block_range, data);

	block->block_range = block_range;
	block = set_movable_stack_place(block, stack_place);
	block->nums_range_per_blocks = set_nums_range_per_blocks(block, data);
	data->now_op = move_for_divide_nums(block, data, error_code);
	return (data->now_op);
}
