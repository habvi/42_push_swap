#ifndef DEQUE_H
# define DEQUE_H

# include <stddef.h>
# include <stdbool.h>

# include <stdio.h> // to do: erase

typedef enum e_error	t_error;

typedef struct s_deque {
	int				num;
	struct s_deque	*next;
	struct s_deque	*prev;
}	t_deque;

// dq_clear.c
void	deque_clear(t_deque *deque);

// dq_init.c
void	deque_init(t_deque *deque);

// dq_new.c
t_deque	*deque_new(int num, t_error *error);

// dq_print.c
void	deque_print(t_deque deque);

bool	deque_is_empty(t_deque deque);
void	deque_append(t_deque *deque, int num, t_error *error);

#endif
