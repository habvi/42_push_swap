#include "ft_dprintf.h"
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"

void	print_operations(t_nums *answer, t_error *error_code)
{
	t_deque				*node;
	static const char	*op_strs[] = {NULL, STR_SA, STR_SB, STR_SS, \
									STR_PA, STR_PB, \
									STR_RA, STR_RB, STR_RR, \
									STR_RRA, STR_RRB, STR_RRR, NULL};

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
			ft_dprintf(STDOUT_FILENO, "%s\n", op_strs[node->num]);
		node = node->next;
	}
}
