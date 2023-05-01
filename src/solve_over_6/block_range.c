#include "deque.h"
#include "push_swap.h"
#include "solve.h"

bool	is_stack_head_num_in_range(t_deque *block_range, t_deque *stack)
{
	const int	first = block_range->first;
	const int	last = block_range->last;
	const int	stack_num = stack->next->num;

	if (first <= stack_num && stack_num <= last)
		return (true);
	return (false);
}

bool	is_stack_next_num_in_range(t_deque *block_range, t_deque *stack)
{
	const int	first = block_range->first;
	const int	last = block_range->last;
	const int	stack_num = stack->next->next->num;

	if (first <= stack_num && stack_num <= last)
		return (true);
	return (false);
}

bool	is_stack_tail_num_in_range(t_deque *block_range, t_deque *stack)
{
	const int	first = block_range->first;
	const int	last = block_range->last;
	const int	stack_num = stack->prev->num;

	if (first <= stack_num && stack_num <= last)
		return (true);
	return (false);
}

bool	is_num_out_of_block_range(\
					t_operation op, t_deque *block_range, t_data *data)
{
	if (op == SA)
		return (is_in_range_for_sa(block_range, data));
	if (op == SB)
		return (is_in_range_for_sb(block_range, data));
	if (op == SS)
		return (is_in_range_for_ss(block_range, data));
	if (op == PA)
		return (is_in_range_for_pa(block_range, data));
	if (op == PB)
		return (is_in_range_for_pb(block_range, data));
	if (op == RA)
		return (is_in_range_for_ra(block_range, data));
	if (op == RB)
		return (is_in_range_for_rb(block_range, data));
	if (op == RR)
		return (is_in_range_for_rr(block_range, data));
	if (op == RRA)
		return (is_in_range_for_rra(block_range, data));
	if (op == RRB)
		return (is_in_range_for_rrb(block_range, data));
	if (op == RRR)
		return (is_in_range_for_rrr(block_range, data));
	return (false);
}
