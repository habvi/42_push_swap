#include <stdlib.h> // EXIT_
#include "push_swap.h"
#include "error.h"
#include "ft_dprintf.h"

int	put_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s\n", ERROR_MSG);
	return (EXIT_FAILURE);
}

int	error_exit(t_nums *nums)
{
	put_error();
	free_nums(nums);
	return (EXIT_FAILURE);
}
