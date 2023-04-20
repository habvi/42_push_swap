#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

#include <stdio.h> // to do: erase

t_nums	*pushback_to_a_and_sort(t_data *data, t_error *error_code)
{
	int	a_head;
	int	b_head;
	int	head;

	// printf("\n>>> %s\n", __func__);
	head = 1;
	while (data->stack_b->size)
	{
		a_head = data->stack_a->deque->next->num;
		b_head = data->stack_b->deque->next->num;
		if (a_head == head)
		{
			ra(data, ONE_OP, RUN, error_code);
			if (*error_code)
				return (NULL);
			head++;
		}
		else if (b_head == head)
		{
			pa(data, RUN, error_code);
			if (*error_code)
				return (NULL);
			ra(data, ONE_OP, RUN, error_code);
			if (*error_code)
				return (NULL);
			head++;
		}
		else
		{
			rb(data, ONE_OP, RUN, error_code);
			if (*error_code)
				return (NULL);
		}
		// deque_print4(data);
	}
	while (data->stack_a->deque->next->num != 1)
	{
		ra(data, ONE_OP, RUN, error_code);
		if (*error_code)
			return (NULL);
	}
	// deque_print4(data);
	return (data->now_op);
}
