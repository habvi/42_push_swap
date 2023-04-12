#include "deque.h"
#include "ft_dprintf.h"

void	deque_print(t_deque *deque, char *deque_name)
{
	t_deque	*node;

	if (deque_is_empty(deque))
	{
		ft_dprintf(STDERR_FILENO, "%s is empty!\n", deque_name);
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

void	deque_print2(\
		t_deque *deque1, char *deque1_name, t_deque *deque2, char *deque2_name)
{
	deque_print(deque1, deque1_name);
	deque_print(deque2, deque2_name);
	ft_dprintf(STDERR_FILENO, "----------\n");
}
