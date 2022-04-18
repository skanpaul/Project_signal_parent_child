NAME	= a.out

CC		= gcc
CFLAG	= -lreadline

SRC		= $(wildcard *.c)

all:
	$(CC) $(CFLAG) $(SRC) -o $(NAME)