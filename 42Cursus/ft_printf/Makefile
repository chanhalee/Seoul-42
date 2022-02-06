# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 15:20:20 by chanhale          #+#    #+#              #
#    Updated: 2022/02/06 15:26:47 by chanhale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			char_format.c \
			hex_format.c \
			int_format.c \
			ptr_format.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
AR		= ar crs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)


clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re