#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_nums	*generate_base_move(t_data *data, t_error *error_code)
{
	// t_deque	*lis_a;

	(void)error_code;
	deque_print4(data);
	// lis_a = calc_stack_a_lis();
	// if (*error_code)
	// 	return ;
	// push_to_b_without_lis();
	// push_to_b_without_lis_with_optimize();
	// if (*error_code)
	// 	return ;
	// pushback_to_a();
	// pushback_to_a_with_optimize();
	return (data->now_op);
}

void	solve_over_5(t_data *data, t_error *error_code)
{
	data->now_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return ;
	data->now_op = generate_base_move(data, error_code);
	// optimize_base_move(now_op, data, error_code);
	print_operations(data->now_op, error_code);
}
