#include "deque.h"
#include "operations.h"
#include "push_swap.h"

static void	rotate_tail_to_head(t_deque *stack)
{
	t_deque	*move_node;

	move_node = deque_pop_back(stack);
	deque_add_front(stack, move_node);
}

void	rra(t_nums *nums)
{
	t_deque			*stack_a;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_a = nums->deque;
	rotate_tail_to_head(stack_a);
}

void	rrb(t_nums *nums)
{
	t_deque			*stack_b;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_b = nums->deque;
	rotate_tail_to_head(stack_b);
}

void	rrr(t_nums *nums1, t_nums *nums2)
{
	rra(nums1);
	rrb(nums2);
}
