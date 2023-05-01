#include <stdlib.h> // free
#include <limits.h>
#include "deque.h"
#include "error.h"
#include "free.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h>

static t_data	*set_dfs_info(t_block *block, t_data *data, t_error *error_code)
{
	int	first;
	int	last;

	data->tmp_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return (NULL);
	data->min_op = init_nums(INT_MAX, error_code);
	if (*error_code)
		return (NULL);
	first = block->block_range->first;
	last = block->block_range->last;
	block->each_block_range = last - first + 1;
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
	// printf("\n>>> extend %s\n", __func__);
	// deque_print4(data);
	// deque_print(data->tmp_op->deque, "tmp_op");
	// deque_print(data->min_op->deque, "min_op");
	free(data->min_op);
	data->min_op = NULL;
	return (data->now_op);
}

t_nums	*search_all_patterns(t_block *block, t_data *data, t_error *error_code)
{
	// printf("\n>>> %s\n", __func__);
	data = set_dfs_info(block, data, error_code);
	if (*error_code)
		return (NULL);
	data->min_op = last_nums_dfs(block, data, error_code);
	if (*error_code)
		return (free_nums(data->min_op));
	// printf("\n>>> before %s\n", __func__);
	// deque_print4(data);
	// deque_print(data->tmp_op->deque, "tmp_op");
	// deque_print(data->min_op->deque, "min_op");
	data = move_min_op(data, data->min_op->deque, error_code);
	// printf("\n>>> move min_op %s\n", __func__);
	// deque_print4(data);
	// deque_print(data->tmp_op->deque, "tmp_op");
	// deque_print(data->min_op->deque, "min_op");
	data->now_op = extend_min_op(data, data->min_op);
	return (data->now_op);
}
