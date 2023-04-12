#include "deque.h"
#include "operations.h"
#include "push_swap.h"

static void	swap_head(t_deque *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_nums *nums)
{
	t_deque			*stack_a;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_a = nums->deque->next;
	swap_head(stack_a);
}

void	sb(t_nums *nums)
{
	t_deque			*stack_b;
	const size_t	size = nums->size;

	if (size < 2)
		return ;
	stack_b = nums->deque->next;
	swap_head(stack_b);
}

void	ss(t_nums *nums1, t_nums *nums2)
{
	sa(nums1);
	sb(nums2);
}
