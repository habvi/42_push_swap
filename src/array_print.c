#include "ft_dprintf.h"
#include "push_swap.h"

void	print_array(int *array, size_t size)
{
	size_t	i;

	ft_dprintf(STDOUT_FILENO, "[array : ");
	i = 0;
	while (i < size)
	{
		ft_dprintf(STDOUT_FILENO, "%d ", array[i]);
		i++;
	}
	ft_dprintf(STDOUT_FILENO, "]\n");
}
