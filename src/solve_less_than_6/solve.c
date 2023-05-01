#include <limits.h>
#include <stdint.h>
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	try_next_operations(t_data *data, t_error *error_code);

// dfs
static void	try_all_patterns(t_data *data, t_error *error_code)
{
	if (is_operation_exceeded_answer_size(data))
		return ;
	if (is_stack_a_sorted(data->stack_a, data->stack_b, data->sorted_array))
	{
		update_answer(data, error_code);
		return ;
	}
	if (is_limit_operation_size(data->now_op->size))
		return ;
	try_next_operations(data, error_code);
}

static void	try_next_operations(t_data *data, t_error *error_code)
{
	t_operation	op_i;

	op_i = 1;
	while (op_i <= TOTAL_OPERATIONS)
	{
		if (!is_valid_operations(op_i, data))
		{
			op_i++;
			continue ;
		}
		run_operation(op_i, data, RUN, error_code);
		if (*error_code)
			return ;
		try_all_patterns(data, error_code);
		if (*error_code)
			return ;
		undo_operation(op_i, data, UNDO, error_code);
		if (*error_code)
			return ;
		op_i++;
	}
}

void	solve_le_6(t_data *data, t_error *error_code)
{
	t_nums	*now_op;
	t_nums	*answer;

	now_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return ;
	data->now_op = now_op;
	answer = init_and_set_pointer(data->allocated_ptrs, INT_MAX, error_code);
	if (*error_code)
		return ;
	data->answer = answer;
	try_all_patterns(data, error_code);
	print_operations(data->answer, error_code);
}
