#include "deque.h"
#include "error.h"
#include "push_swap.h"

t_nums	*dup_nums(t_nums *nums, t_error *error_code)
{
	t_nums	*dup_nums;
	t_deque	*node;
	t_deque	*new_node;

	dup_nums = init_nums(nums->size, error_code);
	if (*error_code)
		return (NULL);
	if (deque_is_empty(nums->deque))
		return (dup_nums);
	node = nums->deque->next;
	while (node)
	{
		new_node = deque_new_node(node->num, NULL, error_code);
		deque_add_back(dup_nums->deque, new_node);
		node = node->next;
	}
	return (dup_nums);
}
