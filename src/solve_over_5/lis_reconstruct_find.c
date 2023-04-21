#include <stdlib.h> // malloc
#include <limits.h>
#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

size_t	find_lis_start_i(int *array_a, size_t size, const int lis_tail)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array_a[i] == lis_tail)
		{
			return (i);
			break ;
		}
		i++;
	}
	return (i);
}

static int	*allocata_array(size_t size, t_error *error_code)
{
	int	*indexes;

	indexes = (int *)malloc(sizeof(int) * size);
	if (indexes == NULL)
	{
		*error_code = ERROR_MALLOC;
		return (NULL);
	}
	return (indexes);
}

static void	init_new_lis_a(t_deque *lis_a)
{
	while (lis_a)
	{
		lis_a->num = INT_MAX;
		lis_a = lis_a->next;
	}
}

static size_t	update_lis_a_by_num(t_nums *lis_a, int num)
{
	t_deque	*node;
	size_t	i;

	node = lis_a->deque->next;
	i = 0;
	while (node)
	{
		if (node->num >= num)
		{
			node->num = num;
			return (i);
		}
		node = node->next;
		i++;
	}
	return (i);
}

int	*find_insert_indexes(\
		t_data *data, t_nums *lis_a, const size_t start_i, t_error *error_code)
{
	int				*indexes;
	size_t			i;
	const size_t	size = data->stack_a->size;
	int				num;

	indexes = allocata_array(size, error_code);
	if (*error_code)
		return (NULL);
	init_new_lis_a(lis_a->deque);
	i = 0;
	while (i < size)
	{
		num = data->copy_a[(start_i + 1 + i) % size];
		indexes[i] = update_lis_a_by_num(lis_a, num);
		i++;
	}
	return (indexes);
}
