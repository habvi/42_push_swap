NAME		:=	push_swap

SRC_DIR		:=	src
SRCS		:=	main.c \
				parse.c \
				push_swap.c

OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

INCLUDE_DIR	:=	include
INCLUDES	:=	-I./$(INCLUDE_DIR)/ -I$(LIBFT_DIR)/$(INCLUDE_DIR)/

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
MKDIR		:=	mkdir -p

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

FORCE:

norm:
	norminette $(SRC_DIR) $(INCLUDE_DIR) $(LIBFT_DIR)

debug:
	$(info >>> default goal : $(.DEFAULT_GOAL))
	$(info >>> name : $(NAME))

.PHONY: all clean fclean re FORCE debug norm


# ./push_swap 2 1 3 6 5 8
# ./push_swap 0 one 2 3
# ./push_swap 0 "4 2 3" 8 10
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# ARG=(4 67 3 87 23); ./push_swap $ARG | ./checker $ARG
