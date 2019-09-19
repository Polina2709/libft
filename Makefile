# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jczech <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:29:26 by jczech            #+#    #+#              #
#    Updated: 2019/09/18 22:42:02 by jczech           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = *.c

OO = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror  -c $(CC) -I libft.h
	ar rc $(NAME) $(OO)
	ranlib $(NAME)

clean:
	rm -f $(OO)

fclean: clean
	rm -f $(NAME)

re: fclean all
