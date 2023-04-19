#include <limits.h>
#include "deque.h" // deque_print
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

static t_nums	*init_and_set_pointer(t_deque *allocated_ptrs, size_t init_num, t_error *error_code)
{
	t_nums	*nums;

	nums = init_nums(init_num, error_code);
	if (*error_code)
		return (NULL);
	set_allocated_pointer(allocated_ptrs, T_NUMS, nums, error_code);
	if (*error_code)
	{
		free_nums(nums);
		return (NULL);
	}
	return (nums);
}

// dfs
static void	try_all_patterns(\
			t_data *data, t_nums *now_op, t_nums *answer, t_error *error_code)
{
	(void)data;
	(void)now_op;
	deque_add_back(answer->deque, deque_new_node(0, "sa", error_code));
	deque_add_back(answer->deque, deque_new_node(0, "sb", error_code));
	deque_add_back(answer->deque, deque_new_node(0, "ss", error_code));
}

void	solve_less_than_6(t_data *data, t_error *error_code)
{
	t_nums	*answer;
	t_nums	*now_op;

	deque_print2(data->stack_a->deque, "stackA", data->stack_b->deque, "stackB");
	now_op = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
		return ;
	answer = init_and_set_pointer(data->allocated_ptrs, INT_MAX, error_code);
	if (*error_code)
		return ;
	try_all_patterns(data, now_op, answer, error_code);
	print_operations(answer);
}
