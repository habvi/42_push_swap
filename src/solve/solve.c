#include "error.h"
#include "free.h"
#include "push_swap.h"

void	solve(t_nums *stack_a, int *sorted_array, t_error *error_code)
{
	t_nums	*stack_b;

	stack_b = init_nums(error_code);
	if (*error_code)
		return ;
	stack_a = compress_number(stack_a, sorted_array);
	free_nums(stack_b);
}
