#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_nums	*generate_base_move(t_data *data, t_error *error_code)
{
	deque_print4(data);
	data->now_op = divide_block_sort(data, error_code);
	return (data->now_op);
}

void	solve_over_6(t_data *data, t_error *error_code)
{
	data->now_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return ;
	data->now_op = generate_base_move(data, error_code);
	if (*error_code)
		return ;
	// optimize_base_move(now_op, data, error_code);
	print_operations(data->now_op, error_code);
}
