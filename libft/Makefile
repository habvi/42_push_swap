LIBFT_DIR	:=	libft
SRC_LIBFT	:=	$(LIBFT_DIR)/ft_atoi_for_pushswap.c \
				$(LIBFT_DIR)/ft_abs.c \
				$(LIBFT_DIR)/ft_isdigit.c \
				$(LIBFT_DIR)/ft_max.c \
				$(LIBFT_DIR)/ft_min.c \
				$(LIBFT_DIR)/ft_putstr_fd.c \
				$(LIBFT_DIR)/ft_split.c \
				$(LIBFT_DIR)/ft_strchr.c \
				$(LIBFT_DIR)/ft_strlcpy.c \
				$(LIBFT_DIR)/ft_strlen.c \
				$(LIBFT_DIR)/ft_substr.c \
				$(LIBFT_DIR)/ft_toupper.c

FT_DPRINTF_DIR	:=	ft_dprintf
SRC_FT_DPRINTF	:=	$(FT_DPRINTF_DIR)/convert_to_str.c \
					$(FT_DPRINTF_DIR)/convert_to_str2.c \
					$(FT_DPRINTF_DIR)/ft_dprintf.c \
					$(FT_DPRINTF_DIR)/handle_info.c \
					$(FT_DPRINTF_DIR)/itoa_utoa_for_printf.c\
					$(FT_DPRINTF_DIR)/parse_format.c \
					$(FT_DPRINTF_DIR)/ptoa_xtoa_for_printf.c \
					$(FT_DPRINTF_DIR)/set_field.c \
					$(FT_DPRINTF_DIR)/set_output.c \
					$(FT_DPRINTF_DIR)/strdup_for_printf.c

NAME		:=	libft.a

SRC_DIR		:=	src
OBJ_DIR		:=	obj
SRCS		:=	$(SRC_FT_DPRINTF) $(SRC_LIBFT)
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
