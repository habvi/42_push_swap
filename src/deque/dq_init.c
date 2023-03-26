#include <stdlib.h> // malloc
#include "deque.h"
#include "error.h"

void	deque_init(t_deque *deque, int init_num, t_deque *init_node)
{
	deque->num = init_num;
	deque->next = init_node;
	deque->prev = init_node;
}

t_deque	*deque_init_head(int init_num, t_error *error)
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
