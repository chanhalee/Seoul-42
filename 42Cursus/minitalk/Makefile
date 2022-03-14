CLIENT	= client
SERVER	= server

B_CLIENT	= client_bonus
B_SERVER	= server_bonus

PF_SRCS	= 	./ft_printf/ft_printf.c \
			./ft_printf/char_format.c \
			./ft_printf/hex_format.c \
			./ft_printf/int_format.c \
			./ft_printf/ptr_format.c \
			./ft_printf/semi_lib.c \

S_SRCS	=	./server_srcs/server.c \

C_SRCS	=	./client_srcs/client.c \
			./client_srcs/ft_atoi_costom.c \

BS_SRCS	=	./server_srcs/server_bonus.c \

BC_SRCS	=	./client_srcs/client_bonus.c \
			./client_srcs/ft_atoi_costom.c \

C_OBJS	= $(C_SRCS:.c=.o)
S_OBJS	= $(S_SRCS:.c=.o)
BC_OBJS	= $(BC_SRCS:.c=.o)
BS_OBJS	= $(BS_SRCS:.c=.o)
PF_OBJS	= $(PF_SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(C_OBJS) $(PF_OBJS)
			$(CC) $(CFLAGS) -o $@ $^

$(SERVER):	$(S_OBJS) $(PF_OBJS)
			$(CC) $(CFLAGS) -o $@ $^

$(B_CLIENT):	$(BC_OBJS) $(PF_OBJS)
				$(CC) $(CFLAGS) -o $@ $^

$(B_SERVER):	$(BS_OBJS) $(PF_OBJS)
				$(CC) $(CFLAGS) -o $@ $^


clean:
		$(RM) $(PF_OBJS)
		$(RM) $(C_OBJS)
		$(RM) $(S_OBJS)
		$(RM) $(BC_OBJS)
		$(RM) $(BS_OBJS)

fclean: clean
		$(RM) $(CLIENT)
		$(RM) $(SERVER)
		$(RM) $(B_CLIENT)
		$(RM) $(B_SERVER)

re: fclean all

bonus:	$(B_CLIENT) $(B_SERVER)

.PHONY: all, bonus, clean, fclean, re