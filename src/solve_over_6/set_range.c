#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_block	*add_wait_blocks(\
			t_block *block, int new_first, int new_last, t_error *error_code)
{
	t_deque	*new_node;

	new_node = deque_new_node_for_block(new_first, new_last, error_code);
	if (*error_code)
		return (NULL);
	deque_add_back(block->wait_blocks, new_node);
	return (block);
}

static t_block	*set_nums_range_array(\
								t_block *block, int new_first, int new_last)
{
	static unsigned int	i = 0;

	block->nums_range_per_blocks[i] = new_first;
	block->nums_range_per_blocks[i + 1] = new_last;
	i += 2;
	if (i == block->total_block_count * 2)
		i = 0;
	return (block);
}

static t_block	*set_next_nums_range(\
			t_block *block, int new_first, int new_last, t_error *error_code)
{
	block = add_wait_blocks(block, new_first, new_last, error_code);
	if (*error_code)
		return (NULL);
	block = set_nums_range_array(block, new_first, new_last);
	return (block);
}

static t_block	*set_block_nums_range(\
				t_block *block, const unsigned block_range, t_error *error_code)
{
	int		new_first;
	int		new_last;
	size_t	i;

	new_last = block->block_range->first - 1;
	i = 0;
	while (i < block->total_block_count)
	{
		new_first = new_last + 1;
		new_last = new_first + block->base_block_size - 1;
		if (i < (block_range % block->total_block_count))
			new_last++;
		if (new_first > new_last)
		{
			i++;
			continue ;
		}
		block = set_next_nums_range(block, new_first, new_last, error_code);
		if (*error_code)
			return (NULL);
		i++;
	}
	return (block);
}

//         500        100
//     (n >= 250)  (n < 250)
// 1-4 :  dfs
//   5 :  2 2 1  ->  3 2
//   6 :  2 2 2  ->  3 3
//   7 :  3 2 2  ->  4 3
//   8 :  3 3 2  ->  4 4
t_block	*set_nums_range_per_blocks(\
							t_block *block, t_data *data, t_error *error_code)
{
	const unsigned int	block_range = \
					block->block_range->last - block->block_range->first + 1;

	if (block_range <= LAST_BLOCK_SIZE)
		return (block);
	block = calc_base_block_size(block, block_range, data);
	block = set_block_nums_range(block, block_range, error_code);
	if (*error_code)
		return (NULL);
	return (block);
}
