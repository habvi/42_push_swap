#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

// stack_place(1-4)
// STACK_A_HEAD --- stackA --- STACK_A_TAIL
// STACK_B_HEAD --- stackB --- STACK_B_TAIL
t_nums	*sort_last_num(t_deque *block_range, t_data *data, t_error *error_code)
{
	const t_stack_place	stack_place = find_the_block_place(block_range, data);

	if (stack_place == STACK_A_HEAD)
		return (data->now_op);
	else if (stack_place == STACK_A_TAIL)
		rra(data, false, RUN, error_code);
	else if (stack_place == STACK_B_HEAD)
		pa(data, RUN, error_code);
	else if (stack_place == STACK_B_TAIL)
	{
		rrb(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pa(data, RUN, error_code);
	}
	if (*error_code)
		return (NULL);
	return (data->now_op);
}
