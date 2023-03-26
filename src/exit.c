#include <stdlib.h> // EXIT_
#include "push_swap.h"
#include "error.h"
#include "ft_dprintf.h"

void	free_nums(t_nums *nums)
{
	deque_clear(&nums->deque);
	free(nums);
}

int	error_exit(t_nums *nums)
{
	ft_dprintf(STDERR_FILENO, "%s\n", ERROR_MSG);
	free_nums(nums);
	return (EXIT_FAILURE);
}
