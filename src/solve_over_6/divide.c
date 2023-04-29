#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

t_nums	*divide_nums_to_other_3_stacks(\
		t_block *block, t_deque *block_range, t_data *data, t_error *error_code)
{
	block->block_range = block_range;
	block = set_block_info(block, block_range, data, error_code);
	if (*error_code)
		return (NULL);
	data->now_op = move_for_divide_nums(block, data, error_code);
	if (*error_code)
		return (NULL);
	return (data->now_op);
}
