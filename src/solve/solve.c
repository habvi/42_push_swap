#include "deque.h"
#include "push_swap.h"

void	solve(t_nums *nums, int *sorted_array)
{
	nums = compress_number(nums, sorted_array);
	deque_print(nums->deque, "stackA"); // to do: erase
}
