#include "deque.h"
#include "operations.h"
#include "push_swap.h"

static void	rotate_head_to_tail(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_front(stack);
	deque_add_back(stack, move_node);
}

void	ra(t_nums *nums)
{
	t_deque			*stack_a;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_a = nums->deque;
	rotate_head_to_tail(stack_a);
}

void	rb(t_nums *nums)
{
	t_deque			*stack_b;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_b = nums->deque;
	rotate_head_to_tail(stack_b);
}

void	rr(t_nums *nums1, t_nums *nums2)
{
	ra(nums1);
	rb(nums2);
}
