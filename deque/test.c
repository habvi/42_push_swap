#include <stdlib.h>
#include "deque.h"
#include "error.h"

static void	init_test(t_deque *deque)
{
	deque_init(deque, 0);
	deque_print(deque);
}

static void	add_front_test(t_deque *deque, int num, t_error *error)
{
	deque_add_front(deque, num, error);
	if (*error)
	{
		printf("Error: malloc\n");
		return ;
	}
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

static void	pop_back_test(t_deque *deque)
{
	t_deque	*pop_node;

	pop_node = deque_pop_back(deque);
	if (pop_node == NULL)
	{
		printf("pop_back failed\n");
		deque_print(deque);
		return ;
	}
	printf("pop_back success: %d\n", pop_node->num);
	free(pop_node);
	deque_print(deque);
}

int	main(void)
{
	t_deque	deque;
	t_error	error;

	error = 0;
	init_test(&deque);

	// to do: if error: free & exit
	add_front_test(&deque, 3, &error);
	add_front_test(&deque, 2, &error);
	add_front_test(&deque, 1, &error);

	// to do: if error: free & exit
	add_back_test(&deque, 4, &error);
	add_back_test(&deque, 5, &error);
	add_back_test(&deque, 6, &error);

	add_front_test(&deque, 0, &error);
	add_back_test(&deque, 7, &error);
	add_front_test(&deque, -1, &error);

	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);
	pop_back_test(&deque);

	add_front_test(&deque, 0, &error);
	add_back_test(&deque, 7, &error);
	add_front_test(&deque, -1, &error);

	// pop_back_test(&deque);

	deque_clear(&deque);
	return (EXIT_SUCCESS);
}
