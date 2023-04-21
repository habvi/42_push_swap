#include <stdlib.h> // free
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_nums	*update_lis_num_from_tail(\
				t_data *data, t_nums *lis_a, const size_t start_i, int *indexes)
{
	int				select_i;
	t_deque			*lis_node;
	size_t			i;
	const size_t	size = data->stack_a->size;
	int				num;

	select_i = lis_a->size - 1;
	lis_node = lis_a->deque->prev;
	i = 0;
	while (i < size)
	{
		num = data->copy_a[(start_i + size - i) % size];
		if (indexes[size - i - 1] == select_i)
		{
			lis_node->num = num;
			lis_node = lis_node->prev;
			select_i--;
		}
		i++;
	}
	free(indexes);
	return (lis_a);
}

t_nums	*reconstruct_lis(t_data *data, t_nums *lis_a, t_error *error_code)
{
	int				*indexes;
	const size_t	size = data->stack_a->size;
	const int		lis_tail = lis_a->deque->prev->num;
	const size_t	start_i = find_lis_start_i(data->copy_a, size, lis_tail);

	indexes = find_insert_indexes(data, lis_a, start_i, error_code);
	if (*error_code)
		return (NULL);
	lis_a = update_lis_num_from_tail(data, lis_a, start_i, indexes);
	return (lis_a);
}
