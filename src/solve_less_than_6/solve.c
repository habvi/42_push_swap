#include <limits.h>
#include "deque.h" // deque_print
#include "error.h"
#include "push_swap.h"
#include "solve.h"

// dfs
static void	try_all_patterns(t_data *data, t_nums *answer, t_error *error_code)
{
	(void)data;
	deque_add_back(answer->deque, deque_new_node(0, "sa", error_code));
	deque_add_back(answer->deque, deque_new_node(0, "sb", error_code));
	deque_add_back(answer->deque, deque_new_node(0, "ss", error_code));
}

void	solve_less_than_6(t_data *data, t_error *error_code)
{
	t_nums	*answer;

	deque_print2(data->stack_a->deque, "stackA", data->stack_b->deque, "stackB");
	answer = init_nums(INT_MAX, error_code);
	if (*error_code)
		return ;
	set_allocated_pointer(data->allocated_ptrs, T_NUMS, answer, error_code);
	if (*error_code)
		return ;
	try_all_patterns(data, answer, error_code);
	print_operations(answer);
}
