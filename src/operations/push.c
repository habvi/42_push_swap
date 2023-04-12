#include "deque.h"
#include "operations.h"
#include "push_swap.h"

void	pa(t_nums *nums1, t_nums *nums2)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	t_deque	*move_node;

	if (deque_is_empty(nums2->deque))
		return ;
	stack_a = nums1->deque;
	stack_b = nums2->deque;
	move_node = deque_pop_front(stack_b);
	deque_add_front(stack_a, move_node);
	nums1->size += 1;
	nums2->size -= 1;
}

void	pb(t_nums *nums1, t_nums *nums2)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	t_deque	*move_node;

	if (deque_is_empty(nums1->deque))
		return ;
	stack_a = nums1->deque;
	stack_b = nums2->deque;
	move_node = deque_pop_front(stack_a);
	deque_add_front(stack_b, move_node);
	nums1->size -= 1;
	nums2->size += 1;
}
