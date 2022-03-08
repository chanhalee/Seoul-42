NAME	= push_swap

SRCS	= 	algorithm_util.c \
			algorithm_merge.c \
			data_structure.c \
			ft_atoll_custom.c \
			ft_split_custom.c \
			iterator_manipulation.c \
			main.c \
			operations.c \
			stack_manipulation.c \
			validate_and_parse_input.c \
			algorithm_special_for_five.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^


clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re