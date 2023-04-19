#include "deque.h"
#include "error.h"
#include "free.h"
#include "push_swap.h"

void	set_allocated_pointer(t_deque *allocated_ptrs, t_type type, void *ptr, t_error *error_code)
{
	t_deque	*new_node;

	new_node = deque_new_node(type, ptr, error_code);
	if (*error_code)
	{
		free_by_each_types(type, ptr);
		return ;
	}
	deque_add_back(allocated_ptrs, new_node);
}
