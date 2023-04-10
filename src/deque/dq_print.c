#include "deque.h"
#include "ft_dprintf.h"

void	deque_print(t_deque *deque, char *deque_name)
{
	t_deque	*node;

	if (deque_is_empty(deque))
	{
		ft_dprintf(STDERR_FILENO, "%s is empty!\n", deque_name);
		ft_dprintf(STDERR_FILENO, "\n");
		return ;
	}
	node = deque->next;
	ft_dprintf(STDERR_FILENO, "[%s:", deque_name);
	while (node)
	{
		ft_dprintf(STDERR_FILENO, " %d", node->num);
		node = node->next;
	}
	ft_dprintf(STDERR_FILENO, "]\n");
}
