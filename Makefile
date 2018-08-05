# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2018/08/05 15:11:26 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCE = main.c visualization.c draw_fractol.c fractols.c other_fractols.c
OBJ = $(SOURCE:.c=.o)
HEADER = fractol.h 

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc libft/libft.a $(OBJ) -I $(HEADER) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o ${NAME}


.c.o:
	gcc -Wall -Wextra -Werror -c $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
