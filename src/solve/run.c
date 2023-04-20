#include <stdint.h>
#include "error.h"
#include "operations.h"
#include "push_swap.h"

// pointer to func list?
void	run_operation(uint8_t op_i, t_data *data, t_error *error_code)
{
	op_i++;
	if (op_i == SA)
		sa(data, ONE_OP, RUN, error_code);
	else if (op_i == SB)
		sb(data, ONE_OP, RUN, error_code);
	else if (op_i == SS)
		ss(data, TWO_OP, RUN, error_code);
	else if (op_i == PA)
		pa(data, RUN, error_code);
	else if (op_i == PB)
		pb(data, RUN, error_code);
	else if (op_i == RA)
		ra(data, ONE_OP, RUN, error_code);
	else if (op_i == RB)
		rb(data, ONE_OP, RUN, error_code);
	else if (op_i == RR)
		rr(data, TWO_OP, RUN, error_code);
	else if (op_i == RRA)
		rra(data, ONE_OP, RUN, error_code);
	else if (op_i == RRB)
		rrb(data, ONE_OP, RUN, error_code);
	else if (op_i == RRR)
		rrr(data, TWO_OP, RUN, error_code);
}

void	undo_operation(uint8_t op_i, t_data *data, t_error *error_code)
{
	op_i++;
	if (op_i == SA)
		sa(data, ONE_OP, UNDO, error_code);
	else if (op_i == SB)
		sb(data, ONE_OP, UNDO, error_code);
	else if (op_i == SS)
		ss(data, TWO_OP, UNDO, error_code);
	else if (op_i == PA)
		pb(data, UNDO, error_code);
	else if (op_i == PB)
		pa(data, UNDO, error_code);
	else if (op_i == RA)
		rra(data, ONE_OP, UNDO, error_code);
	else if (op_i == RB)
		rrb(data, ONE_OP, UNDO, error_code);
	else if (op_i == RR)
		rrr(data, TWO_OP, UNDO, error_code);
	else if (op_i == RRA)
		ra(data, ONE_OP, UNDO, error_code);
	else if (op_i == RRB)
		rb(data, ONE_OP, UNDO, error_code);
	else if (op_i == RRR)
		rr(data, TWO_OP, UNDO, error_code);
}
