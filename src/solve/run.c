#include "error.h"
#include "operations.h"
#include "push_swap.h"

// pointer to func list?
void	run_operation(\
				t_operation op_i, t_data *data, t_run run, t_error *error_code)
{
	if (op_i == SA)
		run_sa(data, run, error_code);
	else if (op_i == SB)
		run_sb(data, run, error_code);
	else if (op_i == SS)
		run_ss(data, run, error_code);
	else if (op_i == PA)
		run_pa(data, run, error_code);
	else if (op_i == PB)
		run_pb(data, run, error_code);
	else if (op_i == RA)
		run_ra(data, run, error_code);
	else if (op_i == RB)
		run_rb(data, run, error_code);
	else if (op_i == RR)
		run_rr(data, run, error_code);
	else if (op_i == RRA)
		run_rra(data, run, error_code);
	else if (op_i == RRB)
		run_rrb(data, run, error_code);
	else if (op_i == RRR)
		run_rrr(data, run, error_code);
}

void	undo_operation(\
				t_operation op_i, t_data *data, t_run run, t_error *error_code)
{
	if (op_i == SA)
		run_sa(data, run, error_code);
	else if (op_i == SB)
		run_sb(data, run, error_code);
	else if (op_i == SS)
		run_ss(data, run, error_code);
	else if (op_i == PA)
		run_pb(data, run, error_code);
	else if (op_i == PB)
		run_pa(data, run, error_code);
	else if (op_i == RA)
		run_rra(data, run, error_code);
	else if (op_i == RB)
		run_rrb(data, run, error_code);
	else if (op_i == RR)
		run_rrr(data, run, error_code);
	else if (op_i == RRA)
		run_ra(data, run, error_code);
	else if (op_i == RRB)
		run_rb(data, run, error_code);
	else if (op_i == RRR)
		run_rr(data, run, error_code);
}
