#include "ft_dprintf.h"
#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"

void	print_operations(t_nums *answer, t_error *error_code)
{
	t_deque				*node;
	static const char	*op_strs[] = {NULL, "sa", "sb", "ss", \
									"pa", "pb", \
									"ra", "rb", "rr", \
									"rra", "rrb", "rrr", NULL};

	if (*error_code)
	{
		ft_dprintf(STDERR_FILENO, "Error malloc\n");
		return ;
	}
	if (answer == NULL || deque_is_empty(answer->deque))
	{
		ft_dprintf(STDERR_FILENO, "op is empty!\n");
		return ;
	}
	node = answer->deque->next;
	while (node)
	{
		if (node->num != OP_NONE)
			ft_dprintf(STDOUT_FILENO, "%s\n", op_strs[node->num]);
		node = node->next;
	}
	ft_dprintf(STDERR_FILENO, "\ntotal: %zu\n", answer->size);
}
