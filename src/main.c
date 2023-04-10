#include <stdlib.h> // EXIT_
#include "error.h"
#include "free.h"
#include "push_swap.h"

static bool	is_valid_argc(int argc)
{
	if (argc <= 1)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_nums	*nums;
	t_error	error_code;

	error_code = 0;
	if (!is_valid_argc(argc))
		return (put_error());
	nums = parse_nums_from_argv(&argv[1], &error_code);
	if (error_code)
		return (error_exit(nums));
	push_swap(nums, &error_code);
	if (error_code)
		return (error_exit(nums));
	free_nums(nums);
	return (EXIT_SUCCESS);
}
