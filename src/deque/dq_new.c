#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"

t_deque	*deque_new_head(int init_num, t_error *error)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (deque == NULL)
	{
		*error = ERROR_MALLOC;
		return (NULL);
	}
	deque->num = init_num;
	deque->next = deque;
	deque->prev = deque;
	return (deque);
}

t_deque	*deque_new_node(int num, t_error *error)
{
	t_deque	*node;

	node = (t_deque *)malloc(sizeof(t_deque));
	if (node == NULL)
	{
		*error = ERROR_MALLOC;
		return (NULL);
	}
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
