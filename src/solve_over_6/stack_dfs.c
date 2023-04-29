#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h>

static bool	is_last_block(t_deque *block_range)
{
	if (block_range->first == block_range->last)
		return (true);
	return (false);
}

static void	*free_block(t_deque	*block_range)
{
	deque_clear(block_range);
	return (NULL);
}

static t_nums	*divide_nums_to_other_3_stacks(\
		t_block *block, t_deque *block_range, t_data *data, t_error *error_code)
{
	(void)data;
	(void)error_code;
	block->block_range = block_range;
	return (data->now_op);
}

t_nums	*stack_dfs(t_block *block, t_data *data, t_error *error_code)
{
	t_deque	*block_range;

	printf("\n>>> %s\n", __func__);
	deque_print(block->wait_blocks, "wating block");
	while (!deque_is_empty(block->wait_blocks))
	{
		block_range = deque_pop_back(block->wait_blocks);
		printf("(first,last):(%d,%d)\n", block_range->first, block_range->last);
		if (is_last_block(block_range))
		{
			data->now_op = sort_from_large_num(block_range, data, error_code);
			if (*error_code)
				return (free_block(block_range));
			deque_clear(block_range);
			continue ;
		}
		data->now_op = divide_nums_to_other_3_stacks(\
								block, block_range, data, error_code);
		if (*error_code)
			return (free_block(block_range));
		deque_clear(block_range);
	}
	return (data->now_op);
}
