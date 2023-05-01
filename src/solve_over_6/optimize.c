#include "deque.h"
#include "error.h"
#include "operations.h"
#include "push_swap.h"
#include "solve.h"

// if erase, now_op->num = 0
t_nums	*optimize_op(t_nums *now_op)
{
	// now_op = replace_op(now_op, RA, RB, RR);
	// now_op = replace_op(now_op, RA, RRR, RRB);
	// now_op = replace_op(now_op, RB, RRR, RRA);
	// now_op = replace_op(now_op, RR, RRA, RB);
	// now_op = replace_op(now_op, RR, RRB, RA);
	// now_op = replace_op(now_op, RRA, RRB, RR);
	// now_op = erase_unnecessary_op(now_op, RA, RRA);
	// now_op = erase_unnecessary_op(now_op, RB, RRB);
	// now_op = erase_unnecessary_op(now_op, RR, RRR);
	// now_op = erase_adjacent_op(now_op, PA, PB);
	return (now_op);
}
