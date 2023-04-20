#include <stdlib.h> // free
#include "deque.h"
#include "error.h"
#include "free.h" // free_nums
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

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
t_nums	*calc_stack_a_lis(t_data *data, t_error *error_code)
{
	int		*array_a;

	array_a = alloc_and_copy_stack_a(data->stack_a, error_code);
	if (*error_code)
		return (NULL);
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
