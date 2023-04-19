NAME		:=	push_swap

#--------------------------------------------
# src
#--------------------------------------------
SRC_DIR		:=	src

#--------------------------------------------
# solve
#--------------------------------------------
ARRAY_DIR			:=	array
OPRATIONS_DIR		:=	operations
SOLVE_DIR			:=	solve
SOLVE_LESS_THAN_DIR	:=	solve_less_than_6
SOLVE_OVER_DIR		:=	solve_over_5

SRCS			:=	$(ARRAY_DIR)/copy.c \
					$(ARRAY_DIR)/print.c \
					$(ARRAY_DIR)/sort.c \
					$(OPRATIONS_DIR)/push.c \
					$(OPRATIONS_DIR)/reverse_rotate.c \
					$(OPRATIONS_DIR)/rotate.c \
					$(OPRATIONS_DIR)/swap.c \
					$(OPRATIONS_DIR)/test.c \
					$(SOLVE_DIR)/compress.c \
					$(SOLVE_DIR)/solve.c \
					$(SOLVE_LESS_THAN_DIR)/solve.c \
					check_nums.c \
					error.c \
					free.c \
					main.c \
					nums.c \
					parse.c \
					push_swap.c \
					set_pointer.c

#--------------------------------------------
# deque
#--------------------------------------------
DEQUE_DIR	:=	deque
DEQUE_SRCS	:=	$(DEQUE_DIR)/dq_add_back.c \
				$(DEQUE_DIR)/dq_add_front.c \
				$(DEQUE_DIR)/dq_clear.c \
				$(DEQUE_DIR)/dq_init.c \
				$(DEQUE_DIR)/dq_is_empty.c \
				$(DEQUE_DIR)/dq_new.c \
				$(DEQUE_DIR)/dq_pop_back.c \
				$(DEQUE_DIR)/dq_pop_front.c \
				$(DEQUE_DIR)/dq_print.c \
				$(DEQUE_DIR)/dq_set_value.c \
				$(DEQUE_DIR)/dq_size.c

#--------------------------------------------
# obj
#--------------------------------------------
OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o) $(DEQUE_SRCS:%.c=$(OBJ_DIR)/%.o)

#--------------------------------------------
# libft
#--------------------------------------------
LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

#--------------------------------------------
# include
#--------------------------------------------
INCLUDE_DIR	:=	include
INCLUDES	:=	-I./$(INCLUDE_DIR)/ -I$(LIBFT_DIR)/$(INCLUDE_DIR)/
DEPS		:=	$(OBJS:.o=.d)

#--------------------------------------------
# to do -> cc
CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
MKDIR		:=	mkdir -p

#--------------------------------------------
all: $(NAME)

-include $(DEPS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

clean:
	$(RM) -r $(OBJ_DIR) $(LIBFT_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

#--------------------------------------------
FORCE:

norm:
	norminette $(SRC_DIR) $(INCLUDE_DIR) $(LIBFT_DIR)

norm_ex_libft:
	norminette $(SRC_DIR) $(INCLUDE_DIR)

info:
	$(info >>> default goal : $(.DEFAULT_GOAL))
	$(info >>> name : $(NAME))
	$(info >>> objs : $(OBJS))

.PHONY: all clean fclean re FORCE info norm norm_ex_libft


# ./push_swap 2 1 3 6 5 8
# ./push_swap 0 one 2 3
# ./push_swap 0 "4 2 3" 8 10
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# ARG=(4 67 3 87 23); ./push_swap $ARG | ./checker $ARG
