#include <stdint.h>
#include "deque.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

bool	is_separate_op(t_operation op)
{
	static const t_operation	ops[] = {SA, SB, SS, PA, PB, OP_NONE};
	uint8_t						i;

	i = 0;
	while (ops[i])
	{
		if (op == ops[i])
			return (true);
		i++;
	}
	return (false);
}

t_nums	*optimize_op(t_nums *now_op)
{
	if (deque_is_empty(now_op->deque))
		return (now_op);
	now_op = replace_op(now_op, RA, RB, RR);
	now_op = replace_op(now_op, RA, RRR, RRB);
	now_op = replace_op(now_op, RB, RRR, RRA);
	now_op = replace_op(now_op, RR, RRA, RB);
	now_op = replace_op(now_op, RR, RRB, RA);
	now_op = replace_op(now_op, RRA, RRB, RRR);
	now_op = erase_pair_op(now_op, RA, RRA);
	now_op = erase_pair_op(now_op, RB, RRB);
	now_op = erase_pair_op(now_op, RR, RRR);
	now_op = erase_adjacent_op(now_op, PA, PB);
	return (now_op);
}
