# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2017/09/11 14:35:26 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCE = main.c
OBJ = $(SOURCE:.c=.o)
HEADER = fractol.h visualization.c draw_fractol.c

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc libft/libft.a $(OBJ) -I $(HEADER) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o ${NAME}


.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
