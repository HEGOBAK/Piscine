SRCS	= ./main.c ./default.c ./default_opt.c ./count_line.c ./error_handling.c ./atoi.c ./opt_c.c 
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_tail
LIBC	= ar rc
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