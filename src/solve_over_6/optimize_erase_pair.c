#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static void	search_right_with_fixed_left(\
			t_deque *node, t_operation left, t_operation op1, t_operation op2)
{
	t_deque		*tmp;
	t_operation	right;

	tmp = node->next;
	while (tmp)
	{
		right = tmp->num;
		if (is_separate_op(right))
			return ;
		if (is_target_pair(left, right, op1, op2))
		{
			node->num = OP_NONE;
			tmp->num = OP_NONE;
			return ;
		}
		tmp = tmp->next;
	}
}

// {sa,sb,ss,pa,pb} x op1or2 x x x op1or2 x x {sa,sb,ss,pa,pb}
// {sa,sb,ss,pa,pb} x    0   x x x    0   x x {sa,sb,ss,pa,pb}
t_nums	*erase_pair_op(t_nums *now_op, t_operation op1, t_operation op2)
{
	t_deque		*node;
	t_operation	left;

	node = now_op->deque->next;
	while (node)
	{
		left = node->num;
		if (!(left == op1 || left == op2))
		{
			node = node->next;
			continue ;
		}
		search_right_with_fixed_left(node, left, op1, op2);
		node = node->next;
	}
	return (now_op);
}
