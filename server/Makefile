# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modaouch <modaouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 17:03:40 by modaouch          #+#    #+#              #
#    Updated: 2019/08/30 11:47:07 by araout           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

SRC =	srcs/main.c\

OBJ = $(SRC:.c=.o)

HEADERS = includes/server.h\



INCLUDES = -Iincludes

DEPEN = $(OBJ) Makefile $(HEADERS)

CC = gcc

CFLAGS +=  -Wall -Wextra -Werror $(INCLUDES)
		#	-g3 -fsanitize=address\
			-fno-omit-frame-pointer\
			-fsanitize-address-use-after-scope

all: $(NAME)

$(NAME): $(DEPEN)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f ./$(NAME)

re: fclean all
