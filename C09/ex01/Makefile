CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
LIBSR = includes/

.PHONY: all clean fclean re

all : libft.a

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -I $(LIBSR) -c

