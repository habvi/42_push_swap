#include "deque.h" // deque_print
#include "error.h"
#include "push_swap.h"
#include "solve.h"

void	solve_less_than_6(t_data data, t_error *error_code)
{
	deque_print(data.stack_a->deque, "stackA");
	deque_print(data.stack_b->deque, "stackB");
	(void)error_code;
	return ;
}
