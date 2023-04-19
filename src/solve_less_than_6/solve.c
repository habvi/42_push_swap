#include <limits.h>
#include "deque.h" // deque_print
#include "error.h"
#include "push_swap.h"
#include "solve.h"

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
	
}
