NAME = minitalk

${NAME}:
	${MAKE} -C ./server_src
	${MAKE} -C ./client_src

clean:
	${MAKE} -C ./server_src clean
	${MAKE} -C ./client_src clean

fclean:
	${MAKE} -C ./server_src fclean
	${MAKE} -C ./client_src fclean

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
