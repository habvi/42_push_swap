#include "push_swap.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_nums	nums;

	if (argc <= 1)
	{
		(void)nums;
		return (SUCCESS);
	}
	if (!parse_nums_from_argv(argv, &nums))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		return (ERROR);
	}
	push_swap(nums);
	return (SUCCESS);
}
