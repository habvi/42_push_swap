#include "deque.h"
#include "error.h"
#include "push_swap.h"
#include "solve.h"

static t_deque	*move_to_target_node(t_deque *stack_a_node, const int lis_tail)
{
	while (stack_a_node)
	{
		if (stack_a_node->num == lis_tail)
			return (stack_a_node);
		stack_a_node = stack_a_node->next;
	}
	return (stack_a_node);
}

static bool	is_update_num(t_deque *stack_a_node, t_deque *new_lis_a_node)
{
	if (new_lis_a_node->num <= stack_a_node->num)
	{
		if (new_lis_a_node->next)
		{
			if (stack_a_node->num <= new_lis_a_node->next->num)
				return (true);
		}
		else
			return (true);
	}
	return (false);
}

static t_deque	*skip_head_node(t_deque *node)
{
	if (node->num == 0)
		return (node->prev);
	return (node);
}

t_nums	*reconstruct_lis(t_nums *stack_a, t_nums *new_lis_a)
{
	const int	lis_tail = new_lis_a->deque->prev->num;
	t_deque		*stack_a_node;
	t_deque		*new_lis_a_node;
	size_t		i;

	stack_a_node = move_to_target_node(stack_a->deque->next, lis_tail);
	new_lis_a_node = new_lis_a->deque->prev;
	i = 0;
	while (i < stack_a->size && new_lis_a_node->num)
	{
		if (is_update_num(stack_a_node, new_lis_a_node))
		{
			new_lis_a_node->num = stack_a_node->num;
			new_lis_a_node = new_lis_a_node->prev;
		}
		stack_a_node = stack_a_node->prev;
		stack_a_node = skip_head_node(stack_a_node);
		i++;
	}
	return (new_lis_a);
}
