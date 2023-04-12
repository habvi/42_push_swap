#include <stdlib.h> // free
#include "deque.h" // deque_print
#include "error.h"
#include "free.h"
#include "operations.h"
#include "push_swap.h"

#include <stdio.h>

void	solve(t_nums *nums, int *sorted_array, t_error *error_code)
{
	t_nums	*stack_a;
	t_nums	*stack_b;

	stack_a = nums;
	stack_b = init_nums(error_code);
	if (*error_code)
		return ;
	stack_a = compress_number(stack_a, sorted_array);

	// test
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	sa(stack_a);
	sb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	ss(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pa(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pa(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	sb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	ss(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pa(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pa(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pa(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");

	printf("=======================================\n");
	ra(stack_a);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	ra(stack_a);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rr(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");

	printf("=======================================\n");
	rra(stack_a);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rra(stack_a);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rrb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rrb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	pb(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rrb(stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");
	rrr(stack_a, stack_b);
	deque_print2(stack_a->deque, "stackA", stack_b->deque, "stackB");

	free_nums(stack_b);
}
