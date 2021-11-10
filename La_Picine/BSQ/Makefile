CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes
NAME = BSQ
SRCS = $(SRCDIR)/file_open.c $(SRCDIR)/main.c $(SRCDIR)/map_check.c $(SRCDIR)/search.c $(SRCDIR)/mem_free.c $(SRCDIR)/std_input.c $(SRCDIR)/print_result.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
