#include "deque.h"
#include <stdio.h> // to do: erase

void	deque_print(t_deque *deque, char *deque_name)
{
	t_deque	*node;

	if (deque_is_empty(deque))
	{
		printf("%s is empty!\n", deque_name);
		printf("---------------------\n");
		return ;
	}
	node = deque->next;
	printf("[%s:", deque_name);
	while (node)
	{
		printf(" %d", node->num);
		node = node->next;
	}
	printf("]\n---------------------\n");
}
