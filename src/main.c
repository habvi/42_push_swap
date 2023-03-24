#include <stdlib.h> // EXIT_
#include "push_swap.h"
#include "ft_dprintf.h"
#include "error.h"

static bool	is_valid_argc(int argc)
{
	if (argc <= 1)
		return (false);
	return (true);
}

static void	error_exit(void)
{
	ft_dprintf(STDERR_FILENO, "%s\n", ERROR_MSG);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_nums	nums;
	bool	error;

	error = false;
	if (!is_valid_argc(argc))
		return (EXIT_FAILURE);
	nums = parse_nums_from_argv(argv, &error);
	if (error)
		error_exit(); // free
	push_swap(nums, &error);
	if (error)
		error_exit();
	return (EXIT_SUCCESS);
}
