#include "ft_dprintf.h"
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"

void	print_operations(t_nums *answer, t_error *error_code)
{
	t_deque				*node;
	static const char	*op_strs[] = {NULL, "sa\n", "sb\n", "ss\n", \
									"pa\n", "pb\n", \
									"ra\n", "rb\n", "rr\n", \
									"rra\n", "rrb\n", "rrr\n", NULL};

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
			ft_dprintf(STDOUT_FILENO, "%s", op_strs[node->num]);
		node = node->next;
	}
}
