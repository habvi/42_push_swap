#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static t_nums	*generate_base_move(t_data *data, t_error *error_code)
{
	printf("\n>>> %s\n", __func__);
	deque_print4(data);
	data->lis_a = calc_stack_a_lis(data, error_code);
	if (*error_code)
		return (NULL);
	deque_print(data->lis_a->deque, "lis_a");
	data->now_op = push_to_b_without_lis(data, error_code);
	// push_to_a_without_lis_with_optimize();
	if (*error_code)
		return (NULL);
	data->now_op = pushback_to_a_and_sort(data, error_code);
	// pushback_to_a_with_optimize();
	return (data->now_op);
}

void	solve_over_5(t_data *data, t_error *error_code)
{
	data->now_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return ;
	data->now_op = generate_base_move(data, error_code);
	if (*error_code)
		return ;
	// deque_print(data->now_op->deque, "now_op-----");
	// optimize_base_move(now_op, data, error_code);
	print_operations(data->now_op, error_code);
}
