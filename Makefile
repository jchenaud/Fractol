# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 09:14:18 by jchenaud          #+#    #+#              #
#    Updated: 2017/04/10 03:57:09 by jchenaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src/
SRC_NAME = $(SRC_PATH)ft_fractol.c\
		   $(SRC_PATH)ft_window.c\
		   $(SRC_PATH)main.c\
		   $(SRC_PATH)tapis.c\
		   $(SRC_PATH)whell.c\
		   $(SRC_PATH)init_and_clear.c\


LIBFT_PATH = libft/
LIBFT_LIB = libft/libft.a


CC = gcc
FLAG = -Wall -Wextra -Werror -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME):
		cd $(LIBFT_PATH) && make re
		$(CC) $(FLAG) $(SRC_NAME) $(LIBFT_LIB) -o $(NAME)
clean:
	cd $(LIBFT_PATH) && make clean

fclean:
	cd $(LIBFT_PATH) && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
