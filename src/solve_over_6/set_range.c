#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static t_block	*set_base_block_size(t_block *block, const int total, t_data *data)
{
	(void)total;
	(void)data;
	return (block);
}

static t_block	*set_block_nums_range(t_block *block, const int total, t_data *data)
{
	(void)total;
	(void)data;
	return (block);
}

t_block	*set_nums_range_per_blocks(t_block *block, t_data *data)
{
	const int	total = block->block_range->last - block->block_range->first + 1;

	if (total <= LAST_BLOCK_SIZE)
		return (block);
	block = set_base_block_size(block, total, data);
	block = set_block_nums_range(block, total, data);
	return (block);
}
