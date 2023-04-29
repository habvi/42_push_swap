#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static void	set_movable_stack_place(t_block *block, t_stack_place stack_place)
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
}

t_nums	*divide_nums_to_other_3_stacks(\
		t_block *block, t_deque *block_range, t_data *data, t_error *error_code)
{
	const t_stack_place	stack_place = find_the_block_place(block_range, data);

	(void)error_code;
	block->block_range = block_range;
	set_movable_stack_place(block, stack_place);
	return (data->now_op);
}
