NAME	=	philo

SRCS	=	./bigbro_util.c \
			./philosopher_thread_control.c \
			./philosopher_thread_main.c \
			./philosopher_thread_util.c \
			./philosophers_main.c \
			./variable_control/clear_bigbro_data.c \
			./variable_control/create_philosopher_data.c \
			./variable_control/free_philosopher_data.c \
			./variable_control/init_bigbro_data.c \
			./utils/ft_atoi.c \
			./utils/ft_get_time_gap.c \
			./utils/ft_strncmp.c \

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@ -Istdlib -Ipthread

all:			$(NAME)


$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			
				make fclean
				make all

.PHONY: 		all, clean, fclean, re