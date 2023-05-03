#ifndef ERROR_H
# define ERROR_H

# define ERROR_MSG	"Error\n"

typedef struct s_nums	t_nums;

typedef enum e_error {
	ERROR_MALLOC = 1,
	ERROR_ARGS = 2,
	ERROR_GNL = 3
}	t_error;

// error.c
int		put_error(void);
int		error_exit(t_nums *nums);

#endif
