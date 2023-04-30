#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static bool	is_executable_size(t_nums *nums)
{
	if (nums->size >= 2)
		return (true);
	return (false);
}

bool	is_executable_operation(t_operation op_i, t_data *data)
{
	if (op_i == SA || op_i == RA || op_i == RRA)
		return (is_executable_size(data->stack_a));
	if (op_i == SB || op_i == RB || op_i == RRB)
		return (is_executable_size(data->stack_b));
	if (op_i == SS || op_i == RR || op_i == RRR)
	{
		return (is_executable_size(data->stack_a) || \
				is_executable_size(data->stack_b));
	}
	if (op_i == PA)
		return (!deque_is_empty(data->stack_b->deque));
	if (op_i == PB)
		return (!deque_is_empty(data->stack_a->deque));
	return (true);
}

bool	is_unnecessary_oparation(t_operation op_i, t_nums *op_deque)
{
	t_operation	pre_op;

	if (op_deque->size == 0)
		return (false);
	pre_op = op_deque->deque->prev->num;
	if (op_i == SA || op_i == SB || op_i == SS)
		return (pre_op == SA || pre_op == SB || pre_op == SS);
	if (op_i == PA)
		return (pre_op == PB);
	if (op_i == PB)
		return (pre_op == PA);
	if (op_i == RA)
		return (pre_op == RB || pre_op == RRA || pre_op == RRR);
	if (op_i == RB)
		return (pre_op == RA || pre_op == RRB || pre_op == RRR);
	if (op_i == RR)
		return (pre_op == RRA || pre_op == RRB || pre_op == RRR);
	if (op_i == RRA)
		return (pre_op == RRB || pre_op == RA || pre_op == RR);
	if (op_i == RRB)
		return (pre_op == RRA || pre_op == RB || pre_op == RR);
	if (op_i == RRR)
		return (pre_op == RA || pre_op == RB || pre_op == RR);
	return (true);
}

bool	is_valid_operations(t_operation op_i, t_data *data)
{
	if (!is_executable_operation(op_i, data))
		return (false);
	if (is_unnecessary_oparation(op_i, data->now_op))
		return (false);
	return (true);
}
