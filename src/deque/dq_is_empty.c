#include "deque.h"
#include <stdio.h>

bool	deque_is_empty(t_deque *deque)
{
	if (deque == deque->next)
		return (true);
	return (false);
}