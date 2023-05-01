#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

static bool	is_target_pair_for_opt(t_optimize *opt)
{
	if (opt->left == opt->before1 && opt->right == opt->before2)
		return (true);
	if (opt->left == opt->before2 && opt->right == opt->before1)
		return (true);
	return (false);
}

static void	search_right_with_fixed_left(t_deque *node, t_optimize *opt)
{
	t_deque		*tmp;
	t_operation	right;

	tmp = node->next;
	while (tmp)
	{
		right = tmp->num;
		if (is_separate_op(right))
			return ;
		opt->right = right;
		if (is_target_pair_for_opt(opt))
		{
			node->num = opt->after;
			tmp->num = OP_NONE;
			return ;
		}
		tmp = tmp->next;
	}
}

// {sa,sb,ss,pa,pb} x before1or2 x x x before1or2 x x {sa,sb,ss,pa,pb}
// {sa,sb,ss,pa,pb} x     after  x x x       0    x x {sa,sb,ss,pa,pb}
t_nums	*replace_op(\
	t_nums *now_op, t_operation before1, t_operation before2, t_operation after)
{
	t_deque		*node;
	t_optimize	opt;
	t_operation	left;

	opt = (t_optimize){.before1 = before1, .before2 = before2, .after = after};
	node = now_op->deque->next;
	while (node)
	{
		left = node->num;
		if (!(left == before1 || left == before2))
		{
			node = node->next;
			continue ;
		}
		opt.left = left;
		search_right_with_fixed_left(node, &opt);
		node = node->next;
	}
	return (now_op);
}
