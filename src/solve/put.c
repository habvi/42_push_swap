#include "ft_dprintf.h"
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"

static const char	*get_op_str(t_operation op_i)
{
	if (op_i == SA)
		return (STR_SA);
	if (op_i == SB)
		return (STR_SB);
	if (op_i == SS)
		return (STR_SS);
	if (op_i == PA)
		return (STR_PA);
	if (op_i == PB)
		return (STR_PB);
	if (op_i == RA)
		return (STR_RA);
	if (op_i == RB)
		return (STR_RB);
	if (op_i == RR)
		return (STR_RR);
	if (op_i == RRA)
		return (STR_RRA);
	if (op_i == RRB)
		return (STR_RRB);
	if (op_i == RRR)
		return (STR_RRR);
	return (NULL);
}

void	print_operations(t_nums *answer, t_error *error_code)
{
	t_deque	*node;

	if (*error_code)
	{
		ft_dprintf(STDERR_FILENO, "Error malloc\n");
		return ;
	}
	if (answer == NULL || deque_is_empty(answer->deque))
		return ;
	node = answer->deque->next;
	while (node)
	{
		if (node->num != OP_NONE)
			ft_dprintf(STDOUT_FILENO, "%s\n", get_op_str(node->num));
		node = node->next;
	}
}
