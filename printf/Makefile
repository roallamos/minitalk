NAME = libftprintf.a

CC = cc

AR = ar

CFLAGS = -Wall -Werror -Wextra

ARFLAGS  = -rcs

SOURCES = ft_putchar.c ft_putstr.c ft_putnbr_base.c ft_putnbr.c ft_printf.c ft_putnbr_unsigned.c

OBJECTS = $(SOURCES:.c=.o)

${NAME}: ${OBJECTS}	
	${AR} ${ARFLAGS} ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
