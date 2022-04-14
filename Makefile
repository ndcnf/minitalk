CC =		CC
CFLAGS =	-Wall -Wextra -Werror #-g -fsanitize=address
NAME =		minitalk
NAME_SRV =	server
NAME_CLI =	client
AR =		ar rcs
SRC_SRV =	server.c
SRC_CLI =	client.c

DIR_LIBFT =	./libft/
LIB_LIBFT =	ft
DIR_FTPRINTF = ./ft_printf/
LIB_FTPRINTF = ftprintf

OBJ_SRV =	${SRC_SRV:.c=.o}
OBJ_CLI =	${SRC_CLI:.c=.o}

all:			${NAME}

${NAME_SRV}:	${OBJ_SRV}
				${CC} ${CFLAGS} \
				-L${DIR_FTPRINTF} -l${LIB_FTPRINTF} \
				-L${DIR_LIBFT} -l${LIB_LIBFT} \
				${OBJ_SRV} -o ${NAME_SRV}

${NAME_CLI}:	${OBJ_CLI}
				${CC} ${CFLAGS} \
				-L${DIR_FTPRINTF} -l${LIB_FTPRINTF} \
				-L${DIR_LIBFT} -l${LIB_LIBFT} \
				${OBJ_CLI} -o ${NAME_CLI}

libs:
				@${MAKE} -sC ${DIR_FTPRINTF}
				@${MAKE} -sC ${DIR_LIBFT}

${NAME}:		libs ${NAME_SRV} ${NAME_CLI}

norm:			all
				norminette ${SRC_SRV} ${SRC_CLI} minitalk.h
clean:
				rm -rf ${OBJ_SRV}
				rm -rf ${OBJ_CLI}
				@${MAKE} -sC ${DIR_LIBFT} clean
				@${MAKE} -sC ${DIR_FTPRINTF} clean

fclean:			clean
				rm -rf ${NAME_SRV}
				rm -rf ${NAME_CLI}

re:				fclean all

.PHONY:			all clean fclean
