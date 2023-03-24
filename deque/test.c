#include <stdlib.h>
#include "deque.h"
#include "error.h"
#include <assert.h>

int	main(void)
{
	t_deque	deque;
	t_error	error;

	error = 0;
	deque_init(&deque);
	deque_print(&deque);

	deque_append(&deque, 5, &error);
	if (error)
		return (EXIT_FAILURE); // to do: free
	deque_print(&deque);

	deque_append(&deque, 3, &error);
	if (error)
		return (EXIT_FAILURE); // to do: free
	deque_print(&deque);

	deque_append(&deque, 9, &error);
	if (error)
		return (EXIT_FAILURE); // to do: free
	deque_print(&deque);

	deque_clear(&deque);
	return (EXIT_SUCCESS);
}
