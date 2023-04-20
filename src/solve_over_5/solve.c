#include <stdlib.h> // malloc
#include "array.h"
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static int	*copy_stack_a(t_nums *stack_a, t_error *error_code)
{
	int		*array_a;
	t_deque	*node;
	size_t	i;

	array_a = (int *)malloc(sizeof(int) * stack_a->size);
	if (array_a == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	node = stack_a->deque->next;
	i = 0;
	while (i < stack_a->size)
	{
		array_a[i] = node->num;
		node = node->next;
		i++;
	}
	return (array_a);
}

static t_deque	*calc_stack_a_lis(t_data *data, t_error *error_code)
{
	int		*array_a;
	// t_deque	*lis_a;

	array_a = copy_stack_a(data->stack_a, error_code);
	if (*error_code)
		return (NULL);
	print_array(array_a, data->stack_a->size, "array_a");
	free(array_a);
	// lis_a = deque_new_head(0, NULL, error_code);
	// if (*error_code)
	// 	return (NULL);
	return (NULL);
}

static t_nums	*generate_base_move(t_data *data, t_error *error_code)
{
	t_deque	*lis_a;

	(void)error_code;
	deque_print4(data);
	lis_a = calc_stack_a_lis(data, error_code);
	if (*error_code)
		return (NULL);
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
