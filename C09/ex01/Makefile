CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
LIBSR = includes/

.PHONY: all clean fclean re

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rcs $(TARGET) $(OBJS)

srcs/ft_putchar.o : srcs/ft_putchar.c
	$(CC) $(FLAGS) -c -I includes -o srcs/ft_putchar.o srcs/ft_putchar.c

srcs/ft_swap.o : srcs/ft_swap.c
	$(CC) $(FLAGS) -c -I includes -o srcs/ft_swap.o srcs/ft_swap.c

srcs/ft_putstr.o : srcs/ft_putstr.c
	$(CC) $(FLAGS) -c -I includes -o srcs/ft_putstr.o srcs/ft_putstr.c

srcs/ft_strlen.o : srcs/ft_strlen.c
	$(CC) $(FLAGS) -c -I includes -o srcs/ft_strlen.o srcs/ft_strlen.c

srcs/ft_strcmp.o : srcs/ft_strcmp.c
	$(CC) $(FLAGS) -c -I includes -o srcs/ft_strcmp.o srcs/ft_strcmp.c

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(TARGET)

re : fclean all
