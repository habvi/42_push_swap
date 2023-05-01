#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

t_nums	*move_from_stack_a_head(\
				const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_TAIL)
		run_ra(data, RUN, error_code);
	else if (after_place == STACK_B_HEAD)
		run_pb(data, RUN, error_code);
	else if (after_place == STACK_B_TAIL)
	{
		run_pb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_rb(data, RUN, error_code);
	}
	return (data->now_op);
}

t_nums	*move_from_stack_a_tail(\
				const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
		run_rra(data, RUN, error_code);
	else if (after_place == STACK_B_HEAD)
	{
		run_rra(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_pb(data, RUN, error_code);
	}
	else if (after_place == STACK_B_TAIL)
	{
		run_rra(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_pb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_rb(data, RUN, error_code);
	}
	return (data->now_op);
}

t_nums	*move_from_stack_b_head(\
				const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
		run_pa(data, RUN, error_code);
	else if (after_place == STACK_A_TAIL)
	{
		run_pa(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_ra(data, RUN, error_code);
	}
	else if (after_place == STACK_B_TAIL)
		run_rb(data, RUN, error_code);
	return (data->now_op);
}

t_nums	*move_from_stack_b_tail(\
				const int after_place, t_data *data, t_error *error_code)
{
	if (after_place == STACK_A_HEAD)
	{
		run_rrb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_pa(data, RUN, error_code);
	}
	else if (after_place == STACK_A_TAIL)
	{
		run_rrb(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_pa(data, RUN, error_code);
		if (*error_code)
			return (NULL);
		run_ra(data, RUN, error_code);
	}
	else if (after_place == STACK_B_HEAD)
		run_rrb(data, RUN, error_code);
	return (data->now_op);
}
