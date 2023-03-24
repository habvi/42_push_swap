#include <stdlib.h>
#include "deque.h"
#include "error.h"

static void	init_test(t_deque *deque)
{
	deque_init(deque);
	deque_print(deque);
}

static void	add_back_test(t_deque *deque, int num, t_error *error)
{
	deque_add_back(deque, num, error);
	if (*error)
	{
		printf("Error: malloc\n");
		return ;
	}
	deque_print(deque);
}

int	main(void)
{
	t_deque	deque;
	t_error	error;

	error = 0;
	init_test(&deque);

	// add_front_test();

	// to do: if error: free & exit
	add_back_test(&deque, 5, &error);
	add_back_test(&deque, 2, &error);
	add_back_test(&deque, -17, &error);
	add_back_test(&deque, 0, &error);

	// pop_front_test();
	// pop_back_test();

	deque_clear(&deque);
	return (EXIT_SUCCESS);
}
