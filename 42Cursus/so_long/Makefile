NAME	= so_long

SRCS	= 	clean_up.c \
			error_manage.c \
			main.c \
			ft_strlen.c \
			ft_putnbr_custom.c \
			get_next_line_utils.c \
			get_next_line.c \
			mlx_control.c \
			mlx_control_key.c \
			movement.c \
			parse_map_util.c \
			parse_map.c \
			variable_control.c \

OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework AppKit


clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re