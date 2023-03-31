#ifndef ERROR_H
# define ERROR_H

# define ERROR_MSG	"Error"

typedef struct s_nums	t_nums;

typedef enum e_error {
	ERROR_MALLOC = 1,
	ERROR_ARGS = 2
}	t_error;

// error.c
int		put_error(void);
int		error_exit(t_nums *nums);

#endif
