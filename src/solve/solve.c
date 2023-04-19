#include "error.h"
#include "push_swap.h"
#include "solve.h"

void	solve(t_data data, t_error *error_code)
{
	data.stack_a = compress_number(data.stack_a, data.sorted_array);
	if (data.stack_a->size < RECURSION_LIMIT)
		solve_less_than_6(data, error_code);
	// else
	// 	solve_over_5()
}
