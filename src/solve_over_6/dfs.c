#include <stdlib.h> // free
#include "deque.h"
#include "error.h"
#include "free.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static t_nums	*last_nums_dfs(t_block *block, t_data *data, t_error *error_code)
{
	(void)block;
	(void)error_code;
	return (data->now_op);
}

static void	extend_min_op(t_nums *now_op, t_nums *min_op)
{
	deque_extend(now_op->deque, min_op->deque);
	now_op->size += min_op->size;
}

t_nums	*search_all_patterns(t_block *block, t_data *data, t_error *error_code)
{
	const unsigned int	block_range = \
					block->block_range->last - block->block_range->first + 1;
	t_nums				*tmp_op;
	t_nums				*min_op;
	int					len_min_op;

	(void)block_range;
	(void)tmp_op;
	(void)len_min_op;
	min_op = init_nums(0, error_code);
	if (*error_code)
		return (NULL);
	// min_op = last_nums_dfs(block, data, error_code);
	data->now_op = last_nums_dfs(block, data, error_code);
	if (*error_code)
		return (free_nums(min_op));
	extend_min_op(data->now_op, min_op);
	free(min_op);
	return (data->now_op);
}
