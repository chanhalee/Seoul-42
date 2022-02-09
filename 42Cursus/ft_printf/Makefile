NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			char_format.c \
			hex_format.c \
			int_format.c \
			ptr_format.c \
			semi_lib.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
AR		= ar crs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I .

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)


clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re