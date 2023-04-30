#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

t_nums	*move_from_stack_a_head(const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_TAIL)
		ra(data, false, RUN, error_code);
	else if (after_place == STACK_B_HEAD)
		pb(data, RUN, error_code);
	else if (after_place == STACK_B_TAIL)
	{
		pb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		rb(data, false, RUN, error_code);
	}
	return (data->now_op);
}

t_nums	*move_from_stack_a_tail(const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
		rra(data, false, RUN, error_code);
	else if (after_place == STACK_B_HEAD)
	{
		rra(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pb(data, RUN, error_code);
	}
	else if (after_place == STACK_B_TAIL)
	{
		rra(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		rb(data, false, RUN, error_code);
	}
	return (data->now_op);
}

t_nums	*move_from_stack_b_head(const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
		pa(data, RUN, error_code);
	else if (after_place == STACK_A_TAIL)
	{
		pa(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		ra(data, false, RUN, error_code);
	}
	else if (after_place == STACK_B_TAIL)
		rb(data, false, RUN, error_code);
	return (data->now_op);
}


t_nums	*move_from_stack_b_tail(const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
	{
		rrb(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pa(data, RUN, error_code);
	}
	else if (after_place == STACK_A_TAIL)
	{
		rrb(data, false, RUN, error_code);
		if (*error_code)
			return (NULL);
		pa(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		ra(data, false, RUN, error_code);
	}
	else if (after_place == STACK_B_HEAD)
		rrb(data, false, RUN, error_code);
	return (data->now_op);
}
