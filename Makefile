NAME	:=	push_swap

#--------------------------------------------
# src
#--------------------------------------------
SRC_DIR	:=	src

#--------------------------------------------
# solve
#--------------------------------------------
SRCS			:=	check_nums.c \
					error.c \
					free.c \
					main.c \
					nums.c \
					parse.c \
					push_swap.c \
					set_pointer.c

ARRAY_DIR		:=	array
SRCS			+=	$(ARRAY_DIR)/copy.c \
					$(ARRAY_DIR)/print.c \
					$(ARRAY_DIR)/sort.c

OPRATIONS_DIR	:=	operations
SRCS			+=	$(OPRATIONS_DIR)/append_op.c \
					$(OPRATIONS_DIR)/pop_op.c \
					$(OPRATIONS_DIR)/push.c \
					$(OPRATIONS_DIR)/reverse_rotate_sub.c \
					$(OPRATIONS_DIR)/reverse_rotate.c \
					$(OPRATIONS_DIR)/rotate_sub.c \
					$(OPRATIONS_DIR)/rotate.c \
					$(OPRATIONS_DIR)/swap_sub.c \
					$(OPRATIONS_DIR)/swap.c

SOLVE_DIR		:=	solve
SRCS			+=	$(SOLVE_DIR)/compress.c \
					$(SOLVE_DIR)/init_set.c \
					$(SOLVE_DIR)/dup_nums.c \
					$(SOLVE_DIR)/put.c \
					$(SOLVE_DIR)/run.c \
					$(SOLVE_DIR)/solve.c

SOLVE_LESS_THAN_DIR	:=	solve_less_than_6
SRCS			+=	$(SOLVE_LESS_THAN_DIR)/dfs.c \
					$(SOLVE_LESS_THAN_DIR)/operations.c \
					$(SOLVE_LESS_THAN_DIR)/solve.c \
					$(SOLVE_LESS_THAN_DIR)/update.c

SOLVE_OVER_DIR	:=	solve_over_6
SRCS			+=	$(SOLVE_OVER_DIR)/block_info.c \
					$(SOLVE_OVER_DIR)/block_range_p.c \
					$(SOLVE_OVER_DIR)/block_range_r.c \
					$(SOLVE_OVER_DIR)/block_range_rr.c \
					$(SOLVE_OVER_DIR)/block_range_s.c \
					$(SOLVE_OVER_DIR)/block_range.c \
					$(SOLVE_OVER_DIR)/calc_block.c \
					$(SOLVE_OVER_DIR)/dfs.c \
					$(SOLVE_OVER_DIR)/divide.c \
					$(SOLVE_OVER_DIR)/init.c \
					$(SOLVE_OVER_DIR)/move_sub.c \
					$(SOLVE_OVER_DIR)/move.c \
					$(SOLVE_OVER_DIR)/optimize_erase_adjacent.c \
					$(SOLVE_OVER_DIR)/optimize_erase_pair.c \
					$(SOLVE_OVER_DIR)/optimize_replace.c \
					$(SOLVE_OVER_DIR)/optimize.c \
					$(SOLVE_OVER_DIR)/search.c \
					$(SOLVE_OVER_DIR)/set_range.c \
					$(SOLVE_OVER_DIR)/solve.c \
					$(SOLVE_OVER_DIR)/sort_last.c \
					$(SOLVE_OVER_DIR)/stack_dfs.c

#--------------------------------------------
# deque
#--------------------------------------------
DEQUE_DIR	:=	deque
DEQUE_SRCS	:=	$(DEQUE_DIR)/dq_add_back.c \
				$(DEQUE_DIR)/dq_add_front.c \
				$(DEQUE_DIR)/dq_clear.c \
				$(DEQUE_DIR)/dq_extend.c \
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
PHONY := all
all: $(NAME)

-include $(DEPS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

PHONY += clean
clean:
	$(RM) -r $(OBJ_DIR) $(LIBFT_DIR)/$(OBJ_DIR)

PHONY += fclean
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(CHECKER)

PHONY += re
re: fclean all

PHONY += FORCE
FORCE:

#--------------------------------------------
# bonus
#--------------------------------------------
# to do: rename -> checker
CHECKER			:=	my_checker

MANDATORY_SRCS	:=	$(filter-out main.c, $(SRCS))
BONUS_DIR		:=	bonus
BONUS_SRCS		:=	$(BONUS_DIR)/check_nums_bonus.c \
					$(BONUS_DIR)/check_op_bonus.c \
					$(BONUS_DIR)/ft_strncmp_bonus.c \
					$(BONUS_DIR)/get_next_line_bonus.c \
					$(BONUS_DIR)/get_next_line_utils_bonus.c \
					$(BONUS_DIR)/main_bonus.c \
					$(BONUS_DIR)/operation_bonus.c \
					$(BONUS_DIR)/put_bonus.c \
					$(BONUS_DIR)/sort_bonus.c

MANDATORY_OBJS	:=	$(filter-out obj/main.o, $(OBJS))
BONUS_OBJS		:=	$(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_DEPS		:=	$(MANDATORY_OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

$(CHECKER): $(MANDATORY_OBJS) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) $(BONUS_OBJS) $(LIBFT)

PHONY += bonus
bonus: $(CHECKER)

# to do: doesn't work..
-include $(BONUS_DEPS)

PHONY += bonus_info
bonus_info:
	$(info >>> m-srcs : $(MANDATORY_SRCS))
	$(info >>> b-srcs : $(BONUS_SRCS))
	$(info >>> m-objs : $(MANDATORY_OBJS))
	$(info >>> b-objs : $(BONUS_OBJS))

#--------------------------------------------
# utils
#--------------------------------------------
PHONY += visu
visu: all
	./visualizer/build/bin/visualizer

PHONY += t4
t4: all
	cd tester && python3 push_swap_tester.py -l 4 -c 20 && cd ..

PHONY += t100
t100: all
	cd tester && python3 push_swap_tester.py -l 100 -c 10 && cd ..

PHONY += test
test: all
	./push_swap 5 -1 9 100 2 6 4 8 3 7

PHONY += test_val
test_val: all
	valgrind ./push_swap 5 -1 9 100 2 6 4 8 3 7

PHONY += val
val: all
	valgrind ./push_swap 86 42 70 31 45 57 89 83 49 95 97 48 11 19 60 22 50 87 15 36 93 77 84 75 73 23 37 99 52 13 74 59 8 4 94 7 3 9 68 39 53 41 56 25 67 24 30 16 91 6 63 65 71 32 1 62 44 28 85 79 72 78 33 55 96 51 17 18 35 14 98 90 26 20 64 82 47 81 40 27 46 100 58 12 61 92 43 10 76 2 38 88 29 54 80 69 5 34 21 66 > out
	cat out | sort | uniq -c

PHONY += norm
norm:
	norminette $(SRC_DIR) $(INCLUDE_DIR) $(LIBFT_DIR)

PHONY += norm_ex_libft
norm_ex_libft:
	norminette $(SRC_DIR) $(INCLUDE_DIR)

PHONY += info
info:
	$(info >>> default goal : $(.DEFAULT_GOAL))
	$(info >>> name : $(NAME))
	$(info >>> objs : $(OBJS))

.PHONY: $(PHONY)
