NAME	= so_long
BONUS_NAME	= so_long_bonus

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

BONUS_SRCS	=	./bonus/clean_up_bonus.c \
				./bonus/enemy_bonus.c \
				./bonus/enemy_util_bonus.c \
				./bonus/error_manage_bonus.c \
				./bonus/main_bonus.c \
				./bonus/ft_strlen_bonus.c \
				./bonus/ft_itoa_custom_bonus.c \
				./bonus/ft_putnbr_custom_bonus.c \
				./bonus/get_next_line_utils_bonus.c \
				./bonus/get_next_line_bonus.c \
				./bonus/mlx_control_bonus.c \
				./bonus/mlx_control_key_bonus.c \
				./bonus/movement_bonus.c \
				./bonus/parse_map_util_bonus.c \
				./bonus/parse_map_bonus.c \
				./bonus/variable_control_bonus.c \

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

bonus:		$(BONUS_NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework AppKit

$(BONUS_NAME):	$(BONUS_OBJS)
			$(CC) $(CFLAGS) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework AppKit

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re