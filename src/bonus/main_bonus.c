#include <stdlib.h> // EXIT_
#include "checker_bonus.h"
#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

static bool	is_valid_argc(const int argc)
{
	if (argc <= 1)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_nums	*stack_a;
	t_error	error_code;

	error_code = 0;
	if (!is_valid_argc(argc))
		return (EXIT_SUCCESS);
	stack_a = parse_nums_from_argv(&argv[1], &error_code);
	if (error_code)
		return (error_exit(stack_a));
	check_op(stack_a, &error_code);
	if (error_code)
		return (error_exit(stack_a));
	free_nums(stack_a);
	return (EXIT_SUCCESS);
}