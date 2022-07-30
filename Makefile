CC = gcc

SRC = $(wildcard src/*.c)
NAME = libmy_malloc.so

CFLAGS = -W -Wall -Wextra -fPIC -shared

all: $(NAME)

$(NAME):
	@ $(CC) -c $(SRC) -I include
	@ $(CC) -o $(NAME) *.o $(CFLAGS)
	@ echo "\033[1;34m[OK] \033[1;32mCompilated library\033[0m\033[1;31m [$(NAME)]\033[0m"

clean:
	@ rm -f *.o
	@ echo "\033[1;34m[OK] \033[1;32mObjects removed\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[1;34m[OK] \033[1;32mBinary removed\033[0m\033[1;31m [$(NAME)]\033[0m"

re:	fclean all
