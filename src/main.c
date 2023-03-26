#include <stdlib.h> // EXIT_
#include "push_swap.h"
#include "error.h"
#include "ft_dprintf.h"

static bool	is_valid_argc(int argc)
{
	if (argc <= 1)
		return (false);
	return (true);
}

static void	error_exit(t_nums *nums)
{
	(void)nums; // to do: free
	ft_dprintf(STDERR_FILENO, "%s\n", ERROR_MSG);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_nums	*nums;
	t_error	error;

	error = 0;
	if (!is_valid_argc(argc))
		return (EXIT_FAILURE);
	nums = parse_nums_from_argv(&argv[1], &error);
	if (error)
		error_exit(nums);
	push_swap(nums, &error);
	if (error)
		error_exit(nums);
	// to do: free
	return (EXIT_SUCCESS);
}
