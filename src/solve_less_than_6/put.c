#include "ft_dprintf.h"
#include "deque.h"
#include "error.h"
#include "push_swap.h"

void	print_operations(t_nums *answer)
{
	t_deque	*node;

	if (deque_is_empty(answer->deque))
	{
		ft_dprintf(STDERR_FILENO, "is empty!\n");
		return ;
	}
	node = answer->deque->next;
	while (node)
	{
		ft_dprintf(STDERR_FILENO, " %s", node->ptr);
		node = node->next;
	}
	ft_dprintf(STDERR_FILENO, "\ntotal: %zu\n", answer->size);
}
