#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static bool	is_block_sorted(t_block *block, t_data *data)
{
	t_deque		*stack_a;
	int			num;
	const int	last_num = block->block_range->last;

	stack_a = data->stack_a->deque->next;
	num = block->block_range->first;
	while (num <= last_num)
	{
		if (stack_a == NULL)
			return (false);
		if (stack_a->num != num)
			return (false);
		stack_a = stack_a->next;
		num++;
	}
	return (true);
}

static bool	is_dfs_end(t_block *block, t_data *data, t_error *error_code)
{
	int	each_block_range;

	if (data->tmp_op->size >= data->min_op->size)
		return (true);
	if (is_block_sorted(block, data))
	{
		update_min_op(data, error_code);
		return (true);
	}
	each_block_range = block->each_block_range;
	if (each_block_range <= BLOCK_3 && data->tmp_op->size == BLOCK_3_LIMIT)
		return (true);
	if (each_block_range == BLOCK_4 && data->tmp_op->size == BLOCK_4_LIMIT)
		return (true);
	return (false);
}

static bool	is_valid_tmp_operations(\
						t_operation op, t_deque *block_range, t_data *data)
{
	if (!is_executable_operation(op, data))
		return (false);
	if (is_unnecessary_oparation(op, data->tmp_op))
		return (false);
	if (is_num_out_of_block_range(op, block_range, data))
		return (false);
	return (true);
}

t_nums	*last_nums_dfs(t_block *block, t_data *data, t_error *error_code)
{
	t_operation	op;

	if (is_dfs_end(block, data, error_code))
		return (data->min_op);
	op = 1;
	while (op <= TOTAL_OPERATIONS)
	{
		if (!is_valid_tmp_operations(op, block->block_range, data))
		{
			op++;
			continue ;
		}
		run_operation(op, data, RUN_TMP_OP, error_code);
		if (*error_code)
			return (NULL);
		data->min_op = last_nums_dfs(block, data, error_code);
		undo_operation(op, data, UNDO_TMP_OP, error_code);
		if (*error_code)
			return (NULL);
		op++;
	}
	return (data->min_op);
}
