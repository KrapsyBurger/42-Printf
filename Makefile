SRCS = ft_printf.c\
ft_display.c\
ft_utility.c

 OBJS        = ${SRCS:.c=.o}

CC        = gcc

CFLAGS        = -Werror -Wall -Wextra

RM        = rm -f

NAME        = libftprintf.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
