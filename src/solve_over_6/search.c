#include <stdlib.h> // free
#include <limits.h>
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static t_data	*set_dfs_info(t_block *block, t_data *data, t_error *error_code)
{
	data->tmp_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return (NULL);
	data->min_op = init_nums(INT_MAX, error_code);
	if (*error_code)
		return (NULL);
	block->each_block_range = block->block_range->last - block->block_range->first + 1;
	return (data);
}

// if run NONE, no error occurred
static t_data	*move_min_op(t_data *data, t_deque *min_op, t_error *error_code)
{
	t_deque	*node;

	if (deque_is_empty(min_op))
		return (data);
	node = min_op->next;
	while (node)
	{
		run_operation(node->num, data, NONE, error_code);
		node = node->next;
	}
	return (data);
}

static t_nums	*extend_min_op(t_data *data, t_nums *min_op)
{
	deque_extend(data->now_op->deque, min_op->deque);
	data->now_op->size += min_op->size;
	free(data->min_op);
	data->min_op = NULL;
	return (data->now_op);
}

t_nums	*search_all_patterns(t_block *block, t_data *data, t_error *error_code)
{
	data = set_dfs_info(block, data, error_code);
	if (*error_code)
		return (NULL);
	data->now_op = last_nums_dfs(block, data, error_code);
	if (*error_code)
		return (NULL);
	data = move_min_op(data, data->min_op->deque, error_code);
	data->now_op = extend_min_op(data, data->min_op);
	return (data->now_op);
}
