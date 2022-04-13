CC =	CC
CFLAGS =	-Wall -Wextra -Werror #-g -fsanitize=address
NAME = minitalk
NAME_SRV = server
NAME_CLI = client
AR =	ar rcs
SRC_SRV = server.c
SRC_CLI = client.c

DIR_LIBFT = ./libft/
LIB_LIBFT = ft

OBJ_SRV = ${SRC_SRV:.c=.o}
OBJ_CLI = ${SRC_CLI:.c=.o}

all:	${NAME}

${NAME_SRV}: ${OBJ_SRV}
		${CC} ${CFLAGS} ${OBJ_SRV} -o ${NAME_SRV}

${NAME_CLI}: ${OBJ_CLI}
		${CC} ${CFLAGS} ${OBJ_CLI} -o ${NAME_CLI}

${NAME}: ${NAME_SRV} ${NAME_CLI}
		
exec:	all
		./server
norm:	all
		norminette ${SRC_SRV} ${SRC_CLI} minitalk.h
clean:
			rm -rf ${OBJ_SRV}
			rm -rf ${OBJ_CLI}
			@${MAKE} -sC ${DIR_LIBFT} clean

fclean:		clean
			rm -rf ${NAME_SRV}
			rm -rf ${NAME_CLI}

re:			fclean all

.PHONY:		all clean fclean
