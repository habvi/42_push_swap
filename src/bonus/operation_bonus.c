#include "checker_bonus.h"
#include "error.h"
#include "get_next_line_bonus.h"
#include "operations.h"

t_operation	get_op_num(const char *op)
{
	if (ft_strcmp(op, STR_SA) == SAME_STRING)
		return (SA);
	if (ft_strcmp(op, STR_SB) == SAME_STRING)
		return (SB);
	if (ft_strcmp(op, STR_SS) == SAME_STRING)
		return (SS);
	if (ft_strcmp(op, STR_PA) == SAME_STRING)
		return (PA);
	if (ft_strcmp(op, STR_PB) == SAME_STRING)
		return (PB);
	if (ft_strcmp(op, STR_RA) == SAME_STRING)
		return (RA);
	if (ft_strcmp(op, STR_RB) == SAME_STRING)
		return (RB);
	if (ft_strcmp(op, STR_RR) == SAME_STRING)
		return (RR);
	if (ft_strcmp(op, STR_RRA) == SAME_STRING)
		return (RRA);
	if (ft_strcmp(op, STR_RRB) == SAME_STRING)
		return (RRB);
	if (ft_strcmp(op, STR_RRR) == SAME_STRING)
		return (RRR);
	return (OP_NONE);
}

bool	is_valid_op(char *line, t_error *error_code)
{
	t_operation	op;

	line = erase_last_new_line(line);
	op = get_op_num(line);
	if (op == OP_NONE)
	{
		*error_code = ERROR_GNL;
		return (false);
	}
	return (true);
}
