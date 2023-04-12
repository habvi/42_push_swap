#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_nums	t_nums;

// operations_push.c
void	pa(t_nums *nums1, t_nums *nums2);
void	pb(t_nums *nums1, t_nums *nums2);

// operations_rotate1.c
void	ra(t_nums *nums);
void	rb(t_nums *nums);
void	rr(t_nums *nums1, t_nums *nums2);

// operations_rotate2.c
void	rra(t_nums *nums);
void	rrb(t_nums *nums);
void	rrr(t_nums *nums1, t_nums *nums2);

// operations_swap.c
void	sa(t_nums *nums);
void	sb(t_nums *nums);
void	ss(t_nums *nums1, t_nums *nums2);

#endif
