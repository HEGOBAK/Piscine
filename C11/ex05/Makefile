SRCS 	= ./do_op.c
OBJS	= ${SRCS:.c=.o}
NAME	= do-op
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o