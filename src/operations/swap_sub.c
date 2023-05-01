#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	swap_head(t_deque *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_data *data)
{
	t_deque			*stack_a;
	const size_t	size = data->stack_a->size;

	if (size < 2)
		return ;
	stack_a = data->stack_a->deque->next;
	swap_head(stack_a);
}

void	sb(t_data *data)
{
	t_deque			*stack_b;
	const size_t	size = data->stack_b->size;

	if (size < 2)
		return ;
	stack_b = data->stack_b->deque->next;
	swap_head(stack_b);
}
