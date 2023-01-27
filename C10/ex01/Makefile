SRCS = cat.c
NAME = ft_cat


all: ${NAME}

$(NAME):
	gcc -Wall -Werror -Wextra -o ${NAME} ${SRCS}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
