#include "ft_dprintf.h"
#include "push_swap.h"

void	print_array(int *array, size_t size, char *array_name)
{
	size_t	i;

	ft_dprintf(STDERR_FILENO, "[%s:", array_name);
	i = 0;
	while (i < size)
	{
		ft_dprintf(STDERR_FILENO, " %d", array[i]);
		i++;
	}
	ft_dprintf(STDERR_FILENO, "]\n");
}
