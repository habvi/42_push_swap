#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"
#include "solve.h"

void	update_lis_a(t_data *data, t_nums *new_lis_a, t_error *error_code)
{
	t_nums	*tmp;
	t_deque	*node;

	tmp = dup_nums(new_lis_a, error_code);
	if (*error_code)
		return ;
	node = data->allocated_ptrs->next;
	while (node)
	{
		if (node->ptr == data->lis_a)
		{
			node->ptr = tmp;
			break ;
		}
		node = node->next;
	}
	free_nums(data->lis_a);
	data->lis_a = tmp;
	data->lis_a->size = new_lis_a->size;
}
