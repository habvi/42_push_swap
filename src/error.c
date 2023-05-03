#include <stdlib.h> // EXIT_
#include "ft_dprintf.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

int	put_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", ERROR_MSG);
	return (EXIT_FAILURE);
}

// error_code : malloc?
int	error_exit(t_nums *nums)
{
	put_error();
	free_nums(nums);
	return (EXIT_FAILURE);
}
