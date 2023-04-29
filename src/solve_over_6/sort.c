#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

t_nums	*divide_block_sort(t_data *data, t_error *error_code)
{
	t_block	block;
	t_deque	*wait_blocks;

	block = init_block();
	wait_blocks = allocate_deque_for_block(data, error_code);
	if (*error_code)
		return (NULL);
	block.wait_blocks = wait_blocks;
	data->now_op = stack_dfs(&block, data, error_code);
	deque_clear(wait_blocks);
	if (*error_code)
		return (NULL);
	return (data->now_op);
}
