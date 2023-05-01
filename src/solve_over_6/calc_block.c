#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_block	*calc_block_size(\
	t_block *block, const unsigned int block_range, unsigned int block_count)
{
	block->total_block_count = block_count;
	block->base_block_size = block_range / block_count;
	return (block);
}

t_block	*calc_base_block_size(\
					t_block *block, const unsigned block_range, t_data *data)
{
	const size_t	total_nums = data->stack_a->size;

	if (total_nums < SWITCH_SOLUTION_NUMS)
	{
		if (block_range <= NUMS_SEPARATE_2)
			block = calc_block_size(block, block_range, SEPARATE_2_BLOCKS);
		else
			block = calc_block_size(block, block_range, SEPARATE_3_BLOCKS);
	}
	else
		block = calc_block_size(block, block_range, SEPARATE_3_BLOCKS);
	return (block);
}
