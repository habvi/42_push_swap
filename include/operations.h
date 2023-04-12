#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_nums	t_nums;

// push.c
void	pa(t_nums *nums1, t_nums *nums2);
void	pb(t_nums *nums1, t_nums *nums2);

// reverse_rotate.c
void	rra(t_nums *nums);
void	rrb(t_nums *nums);
void	rrr(t_nums *nums1, t_nums *nums2);

// rotate.c
void	ra(t_nums *nums);
void	rb(t_nums *nums);
void	rr(t_nums *nums1, t_nums *nums2);

// swap.c
void	sa(t_nums *nums);
void	sb(t_nums *nums);
void	ss(t_nums *nums1, t_nums *nums2);

// test.c
void	test(t_nums *stack_a, t_nums *stack_b);

#endif
