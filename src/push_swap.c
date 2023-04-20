#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

static void	init_pointers(\
			int **array, t_deque **allocated_ptrs, t_error *error_code)
{
	*array = NULL;
	*allocated_ptrs = deque_new_head(0, NULL, error_code);
}

static void	init_stack_b(\
			t_nums **stack_b, t_deque *allocated_ptrs, t_error *error_code)
{
	*stack_b = init_nums(0, error_code);
	if (*error_code)
	{
		free_all_pointers(allocated_ptrs);
		return ;
	}
	set_allocated_pointer(allocated_ptrs, T_NUMS, *stack_b, error_code);
	if (*error_code)
		free_all_pointers(allocated_ptrs);
}

static t_data	init_data(\
		t_nums *stack_a, t_nums *stack_b, int *array, t_deque *allocated_ptrs)
{
	t_data	data;

	data.stack_a = stack_a;
	data.stack_b = stack_b;
	data.sorted_array = array;
	data.allocated_ptrs = allocated_ptrs;
	data.now_op = NULL;
	data.answer = NULL;
	data.lis_a = NULL;
	return (data);
}

void	*push_swap(t_nums *stack_a, t_error *error_code)
{
	int		*array;
	t_deque	*allocated_ptrs;
	t_nums	*stack_b;
	t_data	data;

	init_pointers(&array, &allocated_ptrs, error_code);
	if (*error_code)
		return (NULL);
	// sep: allocate array
	if (!is_valid_stack_nums(stack_a, &array, allocated_ptrs, error_code))
		return (free_all_pointers(allocated_ptrs));
	// in init_data?
	init_stack_b(&stack_b, allocated_ptrs, error_code);
	if (*error_code)
		return (NULL);
	data = init_data(stack_a, stack_b, array, allocated_ptrs);
	solve(&data, error_code);
	free_all_pointers(allocated_ptrs);
	return (NULL);
}
