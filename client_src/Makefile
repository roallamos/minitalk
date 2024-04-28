NAME = client

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

LPATH = ../libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ../printf
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} ${SOURCES} -L ${LPATH} -l ${LNAME} -L ../printf -l ftprintf -o ../${NAME}

clean:
	${MAKE} -C ../libft clean
	${MAKE} -C ../printf clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ../libft fclean
	${MAKE} -C ../printf fclean
	rm -f ../${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
