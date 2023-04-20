#include <stdlib.h> // malloc
#include "array.h" // print_array
#include "deque.h"
#include "error.h"
#include "free.h" // free_nums
#include "push_swap.h"
#include "solve.h"

#include <stdio.h>

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

static void	update_lis_a_by_num(t_nums *new_lis_a, int num, t_error *error_code)
{
	const int	tail = new_lis_a->deque->prev->num;
	t_deque		*new_node;
	t_deque		*node;

	if (tail < num)
	{
		new_node = deque_new_node(num, NULL, error_code);
		if (*error_code)
			return ;
		deque_add_back(new_lis_a->deque, new_node);
		new_lis_a->size++;
	}
	node = new_lis_a->deque;
	while (node)
	{
		if (node->num >= num)
		{
			node->num = num;
			return ;
		}
		node = node->next;
	}
}

static t_deque	*move_to_target_node(t_deque *stack_a_node, const int lis_tail)
{
	while (stack_a_node)
	{
		if (stack_a_node->num == lis_tail)
			return (stack_a_node);
		stack_a_node = stack_a_node->next;
	}
	return (stack_a_node);
}

static t_deque	*skip_head_node(t_deque *node)
{
	if (node->num == 0)
		return (node->prev);
	return (node);
}

static bool	is_update_num(t_deque *stack_a_node, t_deque *new_lis_a_node)
{
	if (new_lis_a_node->num <= stack_a_node->num)
	{
		if (new_lis_a_node->next)
		{
			if (stack_a_node->num <= new_lis_a_node->next->num)
				return (true);
		}
		else
			return (true);
	}
	return (false);
}

static t_nums	*reconstruct_lis(t_nums *stack_a, t_nums *new_lis_a)
{
	const int	lis_tail = new_lis_a->deque->prev->num;
	t_deque		*stack_a_node;
	t_deque		*new_lis_a_node;
	size_t		i;

	stack_a_node = move_to_target_node(stack_a->deque->next, lis_tail);
	new_lis_a_node = new_lis_a->deque->prev;
	i = 0;
	while (i < stack_a->size && new_lis_a_node->num)
	{
		if (is_update_num(stack_a_node, new_lis_a_node))
		{
			new_lis_a_node->num = stack_a_node->num;
			new_lis_a_node = new_lis_a_node->prev;

		}
		stack_a_node = stack_a_node->prev;
		stack_a_node = skip_head_node(stack_a_node);
		i++;
	}
	return (new_lis_a);
}

static t_nums	*calc_each_lis(\
				t_data *data, int *array_a, size_t start_i, t_error *error_code)
{
	t_nums			*new_lis_a;
	size_t			i;
	const size_t	size = data->stack_a->size;
	int				num;

	new_lis_a = init_nums(0, error_code);
	if (*error_code)
		return (NULL);
	i = 0;
	while (i < size)
	{
		num = array_a[(start_i + i) % size];
		update_lis_a_by_num(new_lis_a, num, error_code);
		if (*error_code)
			return (NULL);
		i++;
	}
	deque_print(new_lis_a->deque, "before new_lis");
	new_lis_a = reconstruct_lis(data->stack_a, new_lis_a);
	deque_print(new_lis_a->deque, "after new_lis");
	printf("\n");
	return (new_lis_a);
}

static t_nums	*calc_all_lis_with_rotate(\
					t_data *data, int *array_a, t_error *error_code)
{
	t_nums *new_lis_a;
	size_t	i;

	i = 0;
	while (i < data->stack_a->size)
	{
		printf("start_i index[%zu] : %d\n", i, array_a[i]);
		new_lis_a = calc_each_lis(data, array_a, i, error_code);
		if (*error_code)
			return (NULL);
		if (data->lis_a->size < new_lis_a->size)
			update_lis_a(data, new_lis_a, error_code);
		free_nums(new_lis_a);
		if (*error_code)
			return (NULL);
		i++;
	}
	return (data->lis_a);
}

// LIS: longest increasing subsequence
static t_nums	*calc_stack_a_lis(t_data *data, t_error *error_code)
{
	int		*array_a;

	array_a = copy_stack_a(data->stack_a, error_code);
	if (*error_code)
		return (NULL);
	print_array(array_a, data->stack_a->size, "array_a");
	data->lis_a = init_and_set_pointer(data->allocated_ptrs, 0, error_code);
	if (*error_code)
	{
		free(array_a);
		return (NULL);
	}
	data->lis_a = calc_all_lis_with_rotate(data, array_a, error_code);
	free(array_a);
	return (data->lis_a);
}

static t_nums	*generate_base_move(t_data *data, t_error *error_code)
{
	deque_print4(data);
	data->lis_a = calc_stack_a_lis(data, error_code);
	if (*error_code)
		return (NULL);
	deque_print(data->lis_a->deque, "lis_a");
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
