NAME		:=	libft.a

SRC_DIR		:=	src
SRCS		:=	ft_atoi_with_bool.c \
				ft_isdigit.c \
				ft_min.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_substr.c

OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE_DIR	:=	include
INCLUDES	:=	-I./$(INCLUDE_DIR)/

DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
ARFLAGS		:=	rcs
MKDIR		:=	mkdir -p

all: $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
