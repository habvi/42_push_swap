#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

static size_t	find_head_index(t_data *data, t_dir direction)
{
	t_deque		*node;
	size_t		i;
	const int	lis_a_head = data->lis_a->deque->next->num;

	if (direction == NEXT)
		node = data->stack_a->deque->next;
	else if (direction == PREV)
		node = data->stack_a->deque->prev;
	i = 0;
	while (i < data->stack_a->size)
	{
		if (node->num == lis_a_head)
			break ;
		if (direction == NEXT)
			node = node->next;
		else if (direction == PREV)
			node = node->prev;
		i++;
	}
	if (direction == PREV)
		i++;
	return (i);
}

static t_nums	*rotate_a_until_lis_head(t_data *data, t_error *error_code)
{
	const size_t	ra_count = find_head_index(data, NEXT);
	const size_t	rra_count = find_head_index(data, PREV);
	size_t			i;

	printf("\n>>> %s\n", __func__);
	deque_print4(data);
	printf("ra: %zu, rra: %zu\n", ra_count, rra_count);
	if (ra_count < rra_count)
	{
		i = 0;
		while (i++ < ra_count)
		{
			ra(data, ONE_OP, RUN, error_code);
			if (*error_code)
				return (NULL);
		}
	}
	else
	{
		i = 0;
		while (i++ < rra_count)
		{
			rra(data, ONE_OP, RUN, error_code);
			if (*error_code)
				return (NULL);
		}
	}
	deque_print4(data);
	return (data->now_op);
}

static void	compare_lis_and_run(\
				t_data *data, t_deque **lis_a, t_error *error_code)
{
	t_deque	*stack_a;

	stack_a = data->stack_a->deque->next;
	if (*lis_a && stack_a->num == (*lis_a)->num)
	{
		ra(data, ONE_OP, RUN, error_code);
		*lis_a = (*lis_a)->next;
	}
	else
		pb(data, RUN, error_code);
}

t_nums	*push_to_b_without_lis(t_data *data, t_error *error_code)
{
	t_deque			*lis_a;
	size_t			i;
	const size_t	stack_a_size = data->stack_a->size;

	data->now_op = rotate_a_until_lis_head(data, error_code);
	if (*error_code)
		return (NULL);
	lis_a = data->lis_a->deque->next;
	i = 0;
	while (i < stack_a_size)
	{
		compare_lis_and_run(data, &lis_a, error_code);
		if (*error_code)
			return (NULL);
		i++;
	}
	printf("\n>>> %s\n", __func__);
	deque_print4(data);
	return (data->now_op);
}
