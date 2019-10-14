NAME = client

SRC =	srcs/main.c\

OBJ = $(SRC:.c=.o)

HEADERS = includes/client.h\
		  srcs/lib/libft.h\


LIBPATH = srcs/lib

LIB = $(LIBPATH)/lib.a

INCLUDES = -Iincludes -I$(LIBPATH)

DEPEN = $(OBJ) Makefile $(HEADERS)

CC = gcc

CFLAGS +=  -Wall -Wextra -Werror $(INCLUDES)
		#	-g3 -fsanitize=address\
			-fno-omit-frame-pointer\
			-fsanitize-address-use-after-scope

all: $(NAME)

$(NAME): lib $(DEPEN)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
lib:
	make -C $(LIBPATH) all

clean:
	rm -f $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f ./$(NAME)

re: fclean all
